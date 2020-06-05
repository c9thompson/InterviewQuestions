/*
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/

class Solution {
public:
    vector<int> values;
    
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
    
    Solution(vector<int>& w) : values(w.size() + 1, 0){
        for(int i = 0; i < w.size(); ++i)
            values[i + 1] = values[i] + w[i];

        distribution = std::uniform_real_distribution<double>(0, double(values.back()));
    }
    
    int pickIndex() {
        double number = distribution(generator);
        
        int s = 0;
        int e = values.size() - 1;
        int m = (s + e) / 2;;
        
        while(s != e){
            if(number > values[m] && number < values[m + 1])
                return m;
            else if(number > values[m])
                s = m;
            else
                e = m;
            
            m = (s + e) / 2;
        }
        
        return m;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */