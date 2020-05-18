/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        int letters[26] = {0};
        for(int i = 0; i < s1.size(); ++i)
            letters[s1[i] - 'a']++;

        int negativeCount = 0;
        for(int i = 0; i < s1.size(); ++i){
            negativeCount += (letters[s2[i] - 'a'] == 0);
            letters[s2[i] - 'a']--;
        }

        if(negativeCount == 0) return true;
        for(int i = 1; i <= (s2.size() - s1.size()); ++i){
            negativeCount -= (letters[s2[i - 1] - 'a'] == -1);
            letters[s2[i - 1] - 'a']++;

            negativeCount += (letters[s2[i + s1.size() - 1] - 'a'] == 0);
            letters[s2[i + s1.size() - 1] - 'a']--;

            if(negativeCount == 0) return true; 
        }

        return false;
    }
};