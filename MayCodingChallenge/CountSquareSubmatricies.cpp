/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class Solution {
public:
    int min(int a, int b) { return a < b ? a : b; }
    int min(int a, int b, int c) { return min(a, min(b, c)); }
    
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> squares(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int val;
        int squareCount = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 1){
                    squares[i][j] = 1;
                    squareCount++;
                    
                    if(i > 0 && j > 0){
                        val = min(squares[i - 1][j], squares[i - 1][j - 1], squares[i][j - 1]);
                        squareCount += val;
                        squares[i][j] += val;
                    }
                }
            }
        }
        
        return squareCount;
    }
};