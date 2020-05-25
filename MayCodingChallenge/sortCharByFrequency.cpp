/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

bool sortByValue(const pair<char, int> &a, const pair<char, int> &b) { 
        return (a.second > b.second); 
    }

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> letters(91, pair<char, int>(0, 0));
        
        for(int i = 0; i < s.size(); ++i){
            if(!letters[s[i] - ' '].first) letters[s[i] - ' '].first = s[i];
            letters[s[i] - ' '].second++;
        }
        
        sort(letters.begin(), letters.end(), sortByValue);
        string output = "";
        for(int i = 0; i < letters.size() && letters[i].second != 0; ++i){
            for(int j = 0; j < letters[i].second; ++j)
                output += letters[i].first;
        }
        
        return output;
    }
};