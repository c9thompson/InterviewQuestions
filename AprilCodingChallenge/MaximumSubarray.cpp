/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
/* ------ divide and conquer approach ------ */
    int max(int a, int b) { return a > b ? a : b; }
    int max(int a, int b, int c) { return max(max(a, b), c); }
    
    int crossOver(const vector<int>& nums, int s, int m, int e){
        int sum = 0;
        int left_sum = INT_MIN;
        for(int i = m - 1; i >= s; --i){
            sum += nums[i];
            if(sum > left_sum) left_sum = sum;
        }
        
        sum = 0;
        int right_sum = INT_MIN;
            
        for(int i = m; i < e; ++i){
            sum += nums[i];
            if(sum > right_sum) right_sum = sum;
        }
        
        return left_sum + right_sum;
    }
    
    int divideConquer(const vector<int>& nums, int s, int e){
        if(s == e - 1)
            return nums[s];
        
        int m = (s + e)/2;
        
        int left = divideConquer(nums, s, m);
        int right = divideConquer(nums, m, e);
        int cross = crossOver(nums, s, m, e);
        int maximum = max(left, right, cross);
        
        return maximum;
}
    
    void printVec(vector<int>& nums, int sum, int start, int end){
        cout << sum << ": [ ";
        for(int i = start; i < end - 1; i++)
            cout << nums[i] << ", ";
        cout << nums[nums.size() - 1] << "]" << endl;
    }
    
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        //printVec(nums, 0, start, end);
        int sum = divideConquer(nums, start, end);
        
        //printVec(nums, sum, start, end);
        return sum;
    }

/* ------ O(n) approach ------ */
    
//     int maxSubArray(vector<int>& nums) {
//         int start, end;
//         int sum = nums[0];
//         for(end = 0; end < nums.size(); ++end){
//             if(nums[end] > 0){ 
//                 start = end;
//                 sum = nums[end];
//                 end++;
//                 break;
//             }else if(nums[end] > sum){
//                 sum = nums[end];
//             }
//         }

//         if(sum <= 0) return sum;

//         int largest = sum;
//         while(end < nums.size()){
//             sum += nums[end];
//             if(sum > largest) largest = sum;

//             if(sum <= 0){
//                 end++;
//                 while(end < nums.size() && nums[end] <= 0){
//                     end++;
//                     continue;
//                 }
                
//                 if(end == nums.size()) return largest;
                
//                 start = end;
//                 sum = nums[start];
//                 if(sum > largest) largest = sum;
//             }
            
//             end++;
//         }
        
//         return largest;
//     }

/* ------ ------ ------ ------ ------ */
};