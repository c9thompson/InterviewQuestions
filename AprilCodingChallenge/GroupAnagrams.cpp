/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<char, int> primes = {
            {'a',2}, {'b',3},{'c',5},{'d',7},{'e',11},{'f',13},{'g',17},{'h',19},{'i',23},{'j',29},{'k',31},{'l',37},{'m',41},{'n',43},{'o',47},{'p',53},{'q',59},{'r',61},{'s',67},{'t',71},{'u',73},{'v',79},{'w',83},{'x',89},{'y',97},{'z',101}
        };
        map<int, vector<string>> productSet;
        
        unsigned int primeProduct;
        for(int i = 0; i < strs.size(); ++i){            
            primeProduct = 1;
            // cout << strs[i] << ":" << endl;
            for(int j = 0; j < strs[i].size(); ++j){
                // cout << strs[i][j] << ": " << primes[strs[i][j]] << endl;
                primeProduct *= primes[strs[i][j]];
            }
            // cout << endl;
                        
            if(productSet.find(primeProduct) != productSet.end())
                productSet[primeProduct].push_back(strs[i]);
            else
                productSet[primeProduct] = vector<string>(1, strs[i]);
        }
        
        int i = 0;
        vector<vector<string> > groups(productSet.size());
        for(map<int, vector<string>>::iterator it = productSet.begin(); it != productSet.end(); ++it, ++i){
            // cout << "prime Product " << i << ": " << it->first << endl;
            groups[i] = it->second;
        }
        
        return groups;
    }
};