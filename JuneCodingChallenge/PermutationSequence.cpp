/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string output = "";
        int fact = 1;
        k--;
        
        list<int> num;
        list<int>::iterator it;
        for(int i = 1; i <= n; ++i) {
            num.push_back(i);
            fact *= i;
        }
        
        int rem = 1;
        while(num.size() > 0){
            fact /= num.size();
            rem = k/fact;
            k = k - (rem*fact);
            
            it = num.begin();
            for(int i = 0; i < rem; ++it, ++i);
            output += to_string(*it);
            num.erase(it);            
        }
        
        return output;
    }
};