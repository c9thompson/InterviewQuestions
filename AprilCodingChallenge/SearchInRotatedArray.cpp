/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int binarySearch(int start, int end, vector<int>& nums, int target){
        // cout << "start: " << start << " end: " << end << endl;
        if(start == end - 1) return -1;
        
        int mid = (start + end)/2;
        // cout << "start: " << start << " end: " << end << " mid: " << mid << endl;
        if(nums[mid] == target) return mid;
        if(target < nums[mid]) return binarySearch(start, mid, nums, target);
        if(target > nums[mid]) return binarySearch(mid, end, nums, target);
        
        return -1;
    }
    
    int findPivot(int start, int end, vector<int>& nums, int target){
        // cout << "start: " << start << " end: " << end << endl;
        if(start == end - 1) return end;
        
        int mid = (start + end)/2;
        // cout << "start: " << start << " end: " << end << " mid: " << mid << endl;
        if(nums[mid] == target) return mid;
        if(nums[mid] < nums[mid - 1]) return mid;
        if(nums[mid] > nums[mid + 1]) return mid + 1;
        
        if(nums[start] > nums[mid]) return findPivot(start, mid, nums, target);
        if(nums[mid] > nums[end - 1]) return findPivot(mid, end, nums, target);
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        if(nums.front() == target) return 0;
        if(nums.back() == target) return nums.size() - 1; 
        
        if(nums.size() == 1) return target == nums.front() ? 0 : -1;
        
        if(nums.front() < nums.back()){
            return binarySearch(0, nums.size(), nums, target);
        }else{
            int pivot = findPivot(0, nums.size(), nums, target);
            // cout << "pivot: " << pivot << endl;
            
            if(nums[pivot] == target) return pivot;
            if(nums.front() > target) return binarySearch(pivot, nums.size(), nums, target);

            return binarySearch(0, pivot, nums, target);
        }     
    }
};