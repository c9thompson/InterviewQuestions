/*

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

class Solution {
public:
    int traverse(vector<vector<int>>& grid, int& goodFruit, vector<pair<int, int>> curr){
        int row, col;
        vector<pair<int, int>> next;
        for(int i = 0; i < curr.size(); ++i){
            row = curr[i].first;
            col = curr[i].second;
            
            if(row > 0)
                if(grid[row - 1][col] == 1){
                    next.push_back(pair<int, int>(row - 1, col));
                    goodFruit--;
                    grid[row - 1][col] = 2;
                }
            if(row < (grid.size() - 1))
                if(grid[row + 1][col] == 1){
                    next.push_back(pair<int, int>(row + 1, col));
                    goodFruit--;
                    grid[row + 1][col] = 2;
                }
            if(col > 0)
                if(grid[row][col - 1] == 1){
                    next.push_back(pair<int, int>(row, col - 1));
                    goodFruit--;
                    grid[row][col - 1] = 2;
                }
            if(col < (grid[0].size() - 1))
                if(grid[row][col + 1] == 1){
                    next.push_back(pair<int, int>(row, col + 1));
                    goodFruit--;
                    grid[row][col + 1] = 2;
                }
        }
        
        return next.size() > 0 ? traverse(grid, goodFruit, next) + 1: 0;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int minMax;
        int goodFruit = 0;
        vector<pair<int, int>> next;
        
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1)
                    goodFruit++;
                if(grid[i][j] == 2)
                    next.push_back(pair<int, int>(i, j));
            }
        }
        
        minMax = traverse(grid, goodFruit, next);
        
        return goodFruit > 0 ? -1 : minMax;
    }
};