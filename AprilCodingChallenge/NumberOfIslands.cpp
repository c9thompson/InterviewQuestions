/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    int from2D(int row, int col, int size) { return row*size + col; }
    
    void visit(int row, int col, vector<vector<char>>& grid, vector<bool>& visited){
        visited[from2D(row, col, grid[0].size())] = true;
        
        if(row != 0){
            if(grid[row - 1][col] == '1' && !visited[from2D(row - 1, col, grid[0].size())]){
                visit(row - 1, col, grid, visited);
            }
        }
        
        if(row != grid.size() - 1){
            if(grid[row + 1][col] == '1' && !visited[from2D(row + 1, col, grid[0].size())]){
                visit(row + 1, col, grid, visited);
            }
        }
        
        if(col != 0){
            if(grid[row][col - 1] == '1' && !visited[from2D(row, col - 1, grid[0].size())]){
                visit(row, col - 1, grid, visited);
            }
        }
        
        if(col != grid[0].size() - 1){
            if(grid[row][col + 1] == '1' && !visited[from2D(row, col + 1, grid[0].size())]){
                visit(row, col + 1, grid, visited);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        
        int islandCount = 0;
        vector<bool> visited(grid.size()*grid[0].size());
        
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1' && !visited[from2D(i, j, grid[0].size())]){
                    visit(i, j, grid, visited);
                    islandCount++;
                }
            }
        }
        
        return islandCount;
    }
};