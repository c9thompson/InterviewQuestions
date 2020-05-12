/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        list<int> recent;
        unordered_map<char, list<int>::iterator> count;
        unordered_map<char, list<int>::iterator>::iterator it;
        
        for(int i = 0; i < s.size(); ++i){
            it = count.find(s[i]);
            
            if(it == count.end()){
                recent.push_back(i);
                count[s[i]] = (--recent.end());
            }else{
                if(it->second != recent.end()){
                    recent.erase(it->second);
                    it->second = recent.end();
                }
            }           
        }
        
        return recent.size() > 0 ? recent.front() : -1;
    }
};