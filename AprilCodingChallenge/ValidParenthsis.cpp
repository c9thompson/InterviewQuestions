/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/

class Solution {
public:
    bool checkValidString(string s) {
        if(s == "") return true;
        if(s[s.size() - 1] == '(') return false;
        
        stack<int> stars;
        int bracket = 0;
        int currStars = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '*') currStars++;
            
            if(s[i] == '('){
                stars.push(currStars);
                currStars = 0;
                bracket++;
            }
            
            if(s[i] == ')'){
                if(bracket == 0){
                    if(currStars == 0) return false;
                    else currStars--;
                }else{
                    bracket--;
                    currStars += stars.top();
                    stars.pop();
                }
            }
        }
        
        while(bracket > 0){
            if(currStars == 0) return false;
            
            bracket--;
            currStars = stars.top() + currStars - 1;
            stars.pop();
        }
        
        return true;
        
        // return currStars >= bracket;
    }
};