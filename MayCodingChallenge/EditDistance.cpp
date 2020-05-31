/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

class Solution {
public:
    int min(int a, int b) { return a < b ? a : b; }
    int min(int a, int b, int c) { return min(a, min(b, c)); }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> steps(2, vector<int>(word1.size() + 1, 0));
        
        for(int i = 0; i <= word2.size(); ++i){
            for(int j = 0; j <= word1.size(); ++j){
                if(i == 0) steps[i % 2][j] = j;
                if(j == 0) steps[i % 2][j] = i;
                
                if(i > 0 && j > 0){
                    if(word2[i - 1] == word1[j - 1]){
                        steps[i % 2][j] = steps[(i - 1) % 2][j - 1];
                    }else{
                        steps[i % 2][j] = 1 + min(  steps[(i - 1) % 2][j - 1],  // diagonal
                                                    steps[(i - 1) % 2][j],      // up
                                                    steps[i % 2][j - 1]);       // down
                    }
                }
            }
        }
        
//         for(int i = 0; i < steps.size(); ++i){
//             for(int j = 0; j < steps[0].size() - 1; ++j){
//                 cout << steps[i][j] << ", ";
//             }
            
//             cout << steps[i].back() << endl;
//         } 
        
        return steps[word2.size() % 2].back();
    }
};