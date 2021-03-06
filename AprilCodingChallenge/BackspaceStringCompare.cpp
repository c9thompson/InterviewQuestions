/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        std::stack<char> s;
        std::stack<char> t;
        for(int i = 0; i < S.size() || i < T.size(); ++i){
            if(i < S.size()){
                if(S[i] == '#'){
                    if(s.size() > 0){
                        s.pop();
                    }
                }else{
                    s.push(S[i]);
                }
            }
            
            if(i < T.size()){
                if(T[i] == '#'){
                    if(t.size() > 0){
                        t.pop();
                    }
                }else{
                     t.push(T[i]);
                }
            }
        }
        
        if(s.size() != t.size()) {
            return false;
        }
        
        while(!s.empty()){
            if(s.top() == t.top()){
                s.pop();
                t.pop();
            }else{
                return false;
            }
        }
        
        return true;
    }
};