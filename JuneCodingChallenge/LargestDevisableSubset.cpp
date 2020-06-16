/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        
        sort(nums.begin(), nums.end());

        int max = 0;
        vector<int> diviser(nums.size(), 1);
        vector<int> previous(nums.size(), -1);
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] % nums[j] == 0)
                    if(diviser[i] < (diviser[j] + 1)){
                        diviser[i] = diviser[j] + 1;
                        previous[i] = j;
                    }
            }
            
            if(diviser[max] < diviser[i]) max = i;
        }
        
        vector<int> output;
        while(max >= 0){
            output.push_back(nums[max]);
            max = previous[max];
        }
        
        return output;
    }
    
//     vector<int> dfs(vector<int>& nums, vector<int> currArray, int largest, int i){
//         if(i >= nums.size()) return currArray;
        
//         vector<int> a1 = dfs(nums, currArray, largest, i + 1);
//         if((nums[i] % largest) == 0 || (largest % nums[i]) == 0){
//             currArray.push_back(nums[i]);
//             vector<int> a2 = dfs(nums, currArray, (largest > nums[i] ? largest : nums[i]), i + 1);
            
//             return a1.size() > a2.size() ? a1 : a2;
//         }
        
//         return a1;
//     }
    
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         return dfs(nums, vector<int>(), 1, 0);
//     }
};