/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> prev(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        int v1, v2;
        for(int i = 0; i <= text1.size(); ++i){
            for(int j = 0; j <= text2.size(); ++j){
                if(i == 0 || j == 0){
                    prev[i][j] = 0;
                }else if(text1[i - 1] == text2[j - 1]){
                    prev[i][j] = prev[i - 1][j - 1] + 1;
                }else{
                    v1 = prev[i - 1][j];
                    v2 = prev[i][j - 1];
                    prev[i][j] = v1 > v2 ? v1 : v2;
                }
            }
        }
        
        return prev[text1.size()][text2.size()];
    }
};