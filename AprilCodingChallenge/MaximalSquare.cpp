/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
    int min(int a, int b){
        return a < b ? a : b;
    }
    
    int min(int a, int b, int c){
        return min(a, min(b, c));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        if(matrix[0].empty()) return 0;
        
        int max = 0;
        vector<vector<int>> traversed(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(i == 0 || j == 0){ 
                    traversed[i][j] = matrix[i][j] == '0' ? 0 : 1;
                }else{
                    if(matrix[i][j] == '1') {
                        traversed[i][j] = 1 + min(traversed[i - 1][j], traversed[i][j - 1], traversed[i - 1][j - 1]);  
                    }
                }
                
                if(traversed[i][j] > max) {
                    max = traversed[i][j];
                    // cout << "[" << i << ", " << j << "]: " << max << endl;
                }
                
            // cout << traversed[i][j] << " ";
            }
            // cout << endl;
        }
        
            
        return max*max;
    }
};