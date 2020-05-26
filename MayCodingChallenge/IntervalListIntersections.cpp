/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> output;
        
        int i = 0;
        int j = 0;
        int* eInt;
        int* nInt;
        vector<vector<int>>* early;
        vector<vector<int>>* next;
        
        while(i < A.size() && j < B.size()){
            if(A[i][0] < B[j][0]){
                early = &A;
                eInt = &i;
                next = &B;
                nInt = &j;
            }else{
                early = &B;
                eInt = &j;
                next = &A;
                nInt = &i;
            }
            
            if((*next)[*nInt][0] <= (*early)[*eInt][1]){
                if((*next)[*nInt][1] <= (*early)[*eInt][1]){
                    output.push_back((*next)[*nInt]);
                    (*nInt)++;
                    continue;
                }else{
                    output.push_back(vector<int>({(*next)[*nInt][0],(*early)[*eInt][1]}));       
                }
            }
            
            (*eInt)++;
        }
       
        return output;
    }
};