/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size());
        
        int sumCounter = 0;
        map<int, int> hash;
        map<int, int>::iterator it;
        for(int i = 0; i < sum.size(); ++i){
            sum[i] = nums[i] + (i > 0 ? sum[i - 1] : 0);
            
            if(sum[i] == k) sumCounter++;
            
            it = hash.find(sum[i]);
            if(it != hash.end()) 
                sumCounter += hash[sum[i]];
            
            it = hash.find(sum[i] + k);
            if(it != hash.end()) 
                hash[sum[i] + k]++;
            else 
                hash[sum[i] + k] = 1;
        }
        
        return sumCounter;
    }
};