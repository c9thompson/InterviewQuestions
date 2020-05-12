/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class node{
public:
    node() : dist_(INT_MAX), prev_(-1), visit_(false) {};

    bool visit_;
    int prev_;
    int dist_;
};

class Solution {
public:    
    void to2D(int ind, int colNum, int& row, int& col){
        row = ind/colNum;
        col = ind%colNum;
    }
    
    int gridVal(int ind, vector<vector<int>>& grid){
        int row, col;
        to2D(ind, grid[0].size(), row, col);
        return grid[row][col];
    }
    
    int printPath(int root, vector<node>& nodes, int gridSize){
        if(nodes[root].prev_ < 0) return nodes[root].prev_;
        
        int index = printPath(nodes[root].prev_, nodes, gridSize);
        int row, col;
        to2D(index, gridSize, row, col);
        cout << " [" << row << ", " << col << "]" << " ->";
        
        return nodes[index].prev_;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return -1;
        if(grid[0].size() == 0) return -1;
        
        vector<node> nodes(grid.size()*grid[0].size());
        vector<int> next(2, -1);
        list<int> priority;
        
        nodes[0].dist_ = grid[0][0];
        priority.push_back(0);

        int row, col, newDist, curr;
        while(priority.front() != grid.size()*grid[0].size() - 1){
            curr = priority.front();
            nodes[curr].visit_ = true;
            priority.pop_front();
            
            next[0] = ((curr + 1) % grid[0].size() != 0) ? curr + 1 : -1;
            next[1] = (curr + grid[0].size() < grid.size()*grid[0].size()) ? curr + grid[0].size() : -1;
            
            cout << "curr: " << curr << " right: " << next[0] << " down: " << next[1] << endl;           
            for(int i = 0; i < next.size(); ++i){
                if(next[i] < 0) continue;
                if(nodes[next[i]].visit_) continue;
                
                newDist = nodes[curr].dist_ + gridVal(next[i], grid);
                if(newDist >= nodes[next[i]].dist_) continue;
                
                nodes[next[i]].dist_ = newDist;
                nodes[next[i]].prev_ = curr;
            
                if(priority.empty()) priority.push_back(next[i]);
                else{
                    list<int>::iterator it = priority.begin();
                    for(; it != priority.end(); it++){
                        if(newDist <= nodes[*it].dist_){
                            priority.insert(it, next[i]);
                            break;
                        }
                    }
                    if(it == priority.end()) priority.push_back(next[i]);
                }
            }
        }
        
        // cout << "top value:" << priority.front() << endl; 
        // printPath(priority.front(), nodes, grid[0].size());
        
        return nodes[priority.front()].dist_;
    }
};