/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 

Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000
*/

class Solution {
public:
    int maxUncrossedLinesDP(vector<int>& A, vector<int>& B) {
        
        vector<vector<int>> prev(A.size() + 1, vector<int>(B.size() + 1, 0));

        int v1, v2;
        for(int i = 1; i <= A.size(); ++i){
            for(int j = 1; j <= B.size(); ++j){
                if(A[i - 1] == B[j - 1]){
                    prev[i][j] = prev[i - 1][j - 1] + 1;
                }else{
                    v1 = prev[i - 1][j];
                    v2 = prev[i][j - 1];
                    prev[i][j] = v1 > v2 ? v1 : v2;
                }
            }
        }
        
        return prev[A.size()][B.size()];        
    }
    
//-----------------------Recursion: really slow---------------------------------
    
    int crossLines(vector<int>& A, map<int, list<int>> Bm, int i, int j, int& jMax){
        //cout << "i: " << i << " j: " << j << endl;
        if(i >= A.size() || j >= jMax) {
            //cout << "finished" << endl;
            return 0;
        }
        
        bool sameFlag = false;
        int front;
        int connect = 0;
        map<int, list<int>>::iterator it;
        
        //cout << "entering leave" << endl;
        int leave = crossLines(A, Bm, i + 1, j, jMax);
        
        it = Bm.find(A[i]);
        if(it != Bm.end()){
            while(it->second.size() > 0){
                front = it->second.front();                
                it->second.pop_front();
                if(front >= j){
                    //cout << "front: " << front << endl;
                    //cout << "entering connect" << endl;
                    connect = crossLines(A, Bm, i + 1, front + 1, jMax) + 1;
                    break;
                }
            }
        }
        
        //cout << "i: " << i << " j: " << j << " leave: " << leave << " connect: " << connect << endl;
        
        return connect > leave ? connect : leave;
    }
    
    int maxUncrossedLinesRecurse(vector<int>& A, vector<int>& B) {
        //cout << "A: " << A.size() << " B: " << B.size() << endl;
        map<int, list<int>> Bm; 
        map<int, list<int>>::iterator it;
        for(int i = 0; i < B.size(); ++i){
            //cout << i << endl;
            it = Bm.find(B[i]);
            if(it == Bm.end()) Bm[B[i]] = list<int>(1, i);
            else it->second.push_back(i);
        }
        
        int i = 0;
        int j = 0;
        int maxSize = B.size();
        return crossLines(A, Bm, i, j, maxSize);
      
    }
};