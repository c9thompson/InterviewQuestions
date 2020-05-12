/*
Given a string and an array of shift directions and values. Return the string that has been rotated by the amount described in the array.

Example:

s = bird, shift = [[1,2],[-1, 1],[-1, 3]]
Return: rdbi
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int index = 0;
        for(int i = 0; i < shift.size(); ++i)
            index += (shift[i][0] == 1 ? -1 : 1)*shift[i][1];
        index = (index < 0 ? (index + s.size()*((abs(index)/s.size()) + 1)) : index) % s.size();
        
        vector<char> newString(s.size());
        for(int i = 0; i < s.size(); ++i){
            newString[i] = s[index % s.size()];
            index++;
        } 
        
        return string(newString.begin(), newString.end());
    }
};