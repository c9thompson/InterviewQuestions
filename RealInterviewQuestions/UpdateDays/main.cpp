#include "header.h"
#include "math.h"

void adjacents(int i, vector<int>& adj, vector<int>& grid, int n, vector<int>& visit){
    //left
    if((i % n) != 0)
        if(visit[i - 1] == 0 && grid[i - 1] != 1){
            adj.push_back(i - 1);
            visit[i - 1] = 1;
        }

    //up    
    if((i - n) >= 0)
        if(visit[i - n] == 0 && grid[i - n] != 1){
            adj.push_back(i - n);
            visit[i - n] = 1;
        }

    //right
    if((i + 1) % n != 0)
        if(visit[i + 1] == 0 && grid[i + 1] != 1){
            adj.push_back(i + 1);
            visit[i + 1] = 1;
        }

    //down
    if((i + n) < grid.size())
        if(visit[i + n] == 0 && grid[i + n] != 1){
            adj.push_back(i + n);
            visit[i + n] = 1;
        }

    return;
}

void visualize(vector<int> visit, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << visit[n*i + j] << ',';
        }
        cout << endl;
    }
    cout << endl;
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

    vector<int> currAdj;
    vector<int> visit(grid.size(), 0);

    for(int i = 0; i < grid.size(); ++i){
        if(grid[i] == 1){
            currAdj.push_back(i);
            visit[i] = 1;
        }
    }

    if(currAdj.size() == grid.size()) return 0;

    int waveNum = 0;
    vector<int> nextAdj;
    while(currAdj.size() != 0){
        // visualize(visit, n);
        
        for(int i = 0; i < currAdj.size(); ++i)
            adjacents(currAdj[i], nextAdj, grid, n, visit);

        if(nextAdj.size() != 0){
            currAdj = nextAdj;
            nextAdj.clear();
            waveNum++;
        }else{
            break;
        }
    }

    return waveNum;
}