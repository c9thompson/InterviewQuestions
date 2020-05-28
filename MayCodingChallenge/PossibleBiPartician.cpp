/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/

class Solution {
public:
    bool traverse(int i, bool color, vector<int>& visited, vector<vector<int>>& graph){      
        if(visited[i] < 0){
            visited[i] = color;
            for(int j = 0; j < graph[i].size(); ++j)
                if(!traverse(graph[i][j], !color, visited, graph)) return false;
            
            return true;
        }
        
        return visited[i] == color;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1, vector<int>());
        vector<int> visited(N + 1, -1);
        
        for(int i = 0; i < dislikes.size(); ++i){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i = 1; i < graph.size(); ++i){
            if(visited[i] < 0 && graph[i].size() > 0){
                if(!traverse(i, true, visited, graph))
                    return false;
            }
        }
        
        return true;
    }
};