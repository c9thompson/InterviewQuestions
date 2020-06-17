/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, list<pair<int, int>>& found, int x, int y){
        if(x == 0 || y == 0 || x == (board[0].size() - 1) || y == (board.size() - 1))
            return false;
        else{
            board[y][x] = 'X';
            found.push_back(pair<int, int>(x, y));
            
            bool flag = true;
            if(board[y + 1][x] == 'O' && flag)
                flag = dfs(board, found, x, y + 1);
            if(board[y - 1][x] == 'O' && flag)
                flag = dfs(board, found, x, y - 1);
            if(board[y][x + 1] == 'O' && flag)
                flag = dfs(board, found, x + 1, y);
            if(board[y][x - 1] == 'O' && flag)
                flag = dfs(board, found, x - 1, y);

            while(found.size() > 0 && !flag){
                board[found.back().second][found.back().first] = 'O';
                found.pop_back();
            }
            
            return flag;
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        if(board[0].size() == 0) return;
        
        for(int i = 1; i < board.size() - 1; ++i){
            for(int j = 1; j < board[0].size() - 1; ++j){
                if(board[i][j] == 'O'){
                    list<pair<int, int>> found;
                    dfs(board, found, j, i);
                }
            }
        }
    }
};