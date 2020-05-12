/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool finishFlag;
        int i, j;
        i = j = 0;
        while(i < nums.size()){
            if(nums[i] != 0){
                i++;
                continue;
            }
            
            j = i + 1;
            finishFlag = true;
            while(j < nums.size()){
                if(nums[j] == 0) {
                    j++;
                    continue;
                }else{
                    nums[i] = nums[j];
                    nums[j] = 0;
                    finishFlag = false;
                    break;
                }
            }
            
            if(finishFlag) break;
        }
    }
};