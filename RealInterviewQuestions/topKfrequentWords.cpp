/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

class Solution {
public: 
    
    static bool sortSec(pair<string, int> a, pair<string, int> b){
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second > b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> output;
        map<string, int>::iterator it;

        vector<pair<string, int>> numSort;
        for(int i = 0; i < words.size(); ++i){
            it = output.find(words[i]);
            
            if(it != output.end()) numSort[it->second].second++;
            else{
                numSort.push_back(pair<string, int>(words[i], 1));
                output[words[i]] = numSort.size() - 1;
            }
        }
        
        sort(numSort.begin(), numSort.end(), sortSec);
        
        vector<string> out(k);
        for(int i = 0; i < k; ++i)
            out[i] = numSort[i].first;
        
        return out;
    }
};