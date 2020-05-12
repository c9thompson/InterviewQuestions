/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        vector<int> compoundSum(nums.size(), 0);
        compoundSum[0] = nums[0] == 0 ? -1 : 1;
        int min = compoundSum[0], max = compoundSum[0];
        
        for(int i = 1; i < nums.size(); ++i){
            compoundSum[i] = compoundSum[i - 1] + (nums[i] == 0 ? -1 : 1);
            if(compoundSum[i] < min) min = compoundSum[i];
            if(compoundSum[i] > max) max = compoundSum[i];
        }
        
        int size = -1;
        vector<int> hash(max - min + 1, -1);
        
        for(int i = 0; i < nums.size(); ++i){
            if(compoundSum[i] == 0)
                size = i + 1;
            
            if(hash[compoundSum[i] - min] == -1){
                hash[compoundSum[i] - min] = i; 
            }else{ 
                if((i - hash[compoundSum[i] - min]) > size)
                    size = i - hash[compoundSum[i] - min];
            } 
        }
        
        return size < 0 ? 0 : size;
    }
};