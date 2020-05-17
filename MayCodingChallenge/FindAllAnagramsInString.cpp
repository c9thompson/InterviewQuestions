/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return vector<int>();
        
        int letters[26] = {0};
        for(int i = 0; i < p.size(); ++i)
            letters[p[i] - 'a']++;
        
        int negativeCount = 0;
        for(int i = 0; i < p.size(); ++i){
            negativeCount += (letters[s[i] - 'a'] == 0);
            letters[s[i] - 'a']--;
        }
        
        vector<int> anagrams;
        if(negativeCount == 0) anagrams.push_back(0);
        for(int i = 1; i <= (s.size() - p.size()); ++i){
            negativeCount -= (letters[s[i - 1] - 'a'] == -1);
            letters[s[i - 1] - 'a']++;
            
            negativeCount += (letters[s[i + p.size() - 1] - 'a'] == 0);
            letters[s[i + p.size() - 1] - 'a']--;
            
            if(negativeCount == 0) anagrams.push_back(i); 
        }
        
        return anagrams;
    }
};