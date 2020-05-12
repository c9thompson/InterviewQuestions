/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() % 2 == 0) return -1; 
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()/2; i++)
            if(nums[i*2] != nums[i*2 + 1]) return nums[i*2];
        
        return nums[nums.size() - 1];
    }
};