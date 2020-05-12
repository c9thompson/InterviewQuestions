/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

class Solution {
public:
    void printList(list<int>& list){
        cout << "[ ";
        std::list<int>::iterator it = list.begin();
        for(; it != list.end(); it++)
            cout << *it << " ";
        cout << "]" <<endl;
    }
    
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        list<int> stoneList(stones.rbegin(), stones.rend());
        
        int val;
        int min = stoneList.back();
        std::list<int>::iterator it;
        while(stoneList.size() > 1){
            //printList(stoneList);
            
            val = stoneList.front();
            stoneList.pop_front();
            val = abs(val - stoneList.front());
            stoneList.pop_front();
            
            if(stoneList.size() == 0) return val;
            
            if(val != 0){
                if(val <= min){
                    stoneList.push_back(val);
                    min = val;
                }else{
                    it = stoneList.begin();
                    for(; it != stoneList.end(); it++){
                        if(val >= *it) {
                            stoneList.insert(it, val);
                            break;
                        }
                    }
                }
            }
        }
        
        return (stoneList.size() == 1) ? stoneList.front() : val;
    }
};