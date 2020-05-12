/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() % 2 == 0) return -1;
        if(nums.size() == 1) return nums.front();
        
        int s = 0;
        int e = nums.size() - 1;
        int m;
        bool notBelow;
        
        if(nums[s + 1] != nums[s]) return nums[s];
        if(nums[e] != nums[e - 1]) return nums[e];
        
        while(s != e){
            cout << "s: " << s << " e: " << e << endl;
            m = (s + e)/2;
            notBelow = nums[m] != nums[m - 1];
            if(nums[m] != nums[m + 1] && notBelow) return nums[m];

            if(m % 2 == 0){
                if(notBelow) s = m;
                else e = m;
            }else{
                if(notBelow) e = m;
                else s = m;
            }
        }
        
        return nums[s];
    }
};