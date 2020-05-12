/*
Given an array of all integers return the count of all elements that exist in the an array which are the first increment of another element in the array.

[1,2,2,5,6]

Return 3

*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> hash;
        for(int i = 0; i < arr.size(); ++i)
            hash.insert(arr[i]);
        
        int count = 0;
        for(int i = 0; i < arr.size(); ++i)
            if(hash.find(arr[i] + 1) != hash.end()) count++;
        
        return count;
    }
};