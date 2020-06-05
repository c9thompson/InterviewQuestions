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
    
    int min(int a, int b) { return a < b ? a : b; }
    
    static bool sortSec(pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
    }
    
    static bool sortString(string a, string b){
        return a < b;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> output;
        map<string, int>::iterator it;
        for(int i = 0; i < words.size(); ++i){
            it = output.find(words[i]);
            
            if(it != output.end()){
                it->second++;
            }else{
                output[words[i]] = 1;
            }
        }
        
        it = output.begin();
        vector<pair<string, int>> numSort(output.size());
        for(int i = 0; it != output.end(); ++it, ++i)
            numSort[i] = *it;
        
        sort(numSort.begin(), numSort.end(), sortSec);
        
        int i = 1;
        int currNum = numSort.front().second;
        vector<string> tmp(1, numSort.front().first);
        vector<string> out;
        
        while(out.size() < k && i < numSort.size()){
            if(numSort[i].second == currNum){
                tmp.push_back(numSort[i].first);
            }else{
                sort(tmp.begin(), tmp.end(), sortString);
                out.insert(out.end(), tmp.begin(), tmp.end());
                
                tmp = vector<string>(1, numSort[i].first);
                currNum = numSort[i].second;
            }
        
            i++;
        }
        
        sort(tmp.begin(), tmp.end(), sortString);
        out.insert(out.end(), tmp.begin(), tmp.end());
        
        return vector<string>(out.begin(), out.begin() + min(k, out.size()));
    }
};