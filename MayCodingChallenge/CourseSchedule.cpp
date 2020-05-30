/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

class Solution {
public:
    bool makeCircle(vector<list<int>>& graph, vector<bool>& visit, vector<bool>& path, int i){
        if(visit[i]) return false;
        
        visit[i] = true;
        path[i] = true;
        list<int>::iterator it = graph[i].begin();
        for(; it != graph[i].end(); ++it)
            if(path[*it] || makeCircle(graph, visit, path, *it)) return true;
        
        path[i] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<list<int>> graph(numCourses, list<int>());
        
        for(int i = 0; i < prerequisites.size(); ++i)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<bool> visit(numCourses, 0);
        vector<bool> path(numCourses, 0);
        for(int i = 0; i < numCourses; ++i){
            if(!visit[i] && makeCircle(graph, visit, path, i)) return false;
        }
        
        return true;
    }
    
//     bool traverse(vector<list<int>>& forward, vector<list<int>> backward, vector<bool>visit, int curr, int prev){
//         int next;
//         bool result = true;
        
//         //move backwards
//         int size = backward[curr].size();
//         for(int i = 0; (i < size) && result; ++i){
//             next = backward[curr].front();
//             backward[curr].pop_front();
            
//             if(visit[next] || next == prev) continue;
//             result = traverse(forward, backward, visit, next, curr);
//         }
        
//         //move forwards
//         visit[curr] = true;
//         size = forward[curr].size();
//         for(int i = 0; (i < size) && result; ++i){
//             next = forward[curr].front();
//             forward[curr].pop_front();
            
//             if(next == prev) continue;
//             if(visit[next]) return false;
//             result = traverse(forward, backward, visit, next, curr);
//         }
        
//         return result;
//     }
    
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<list<int>> forward(numCourses, list<int>());
//         vector<list<int>> backward(numCourses, list<int>());
        
//         vector<bool> visit(numCourses, 0);
//         for(int i = 0; i < prerequisites.size(); ++i){
//             forward[prerequisites[i][1]].push_back(prerequisites[i][0]);
//             backward[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
        
//         for(int i = 0; i < numCourses; ++i){
//             if(forward[i].size() != 0){
//                 if(!traverse(forward, backward, visit, i, -1)) return false;
//             }
//         }
        
//         return true;
//     }
};