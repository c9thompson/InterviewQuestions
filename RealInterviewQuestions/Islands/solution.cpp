#include "header.h"
#include "math.h"


void traverse(int i, vector<int>& grid, int n, vector<int>& visit){
    visit[i] = 1;

    //left
    if((i % n) != 0)
        if(visit[i - 1] == 0 && grid[i - 1] == 1)
            traverse(i - 1, grid, n, visit);

    //up    
    if((i - n) >= 0)
        if(visit[i - n] == 0 && grid[i - n] == 1)
            traverse(i - n, grid, n, visit);

    //right
    if((i + 1) % n != 0)
        if(visit[i + 1] == 0 && grid[i + 1] == 1)
            traverse(i + 1, grid, n, visit);

    //down
    if((i + n) < grid.size())
        if(visit[i + n] == 0 && grid[i + n] == 1)
            traverse(i + n, grid, n, visit);

    return;
}

int solution(vector<int> grid){
    if(grid.size() < 1)
        return -1;
    else if(grid.size() == 1)
        return grid[0];

    int n = sqrt(grid.size());

    if(n*n != grid.size())
        return -1;

    vector<int> visit(grid.size(), 0);

    int clusterNum = 0;
    for(int i = 0; i < grid.size(); ++i){
        if(grid[i] == 1 && visit[i] == 0){
            traverse(i, grid, n, visit);
            clusterNum++;
        }
    }

    return clusterNum;
}