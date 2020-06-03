/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
*/

class Solution {
public:
    int min(int a, int b) { return a < b ? a : b; }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                if(i == 0 && j == 0) continue;
                
                if(i == 0) dp[i % 2][j] = dp[i % 2][j - 1] + costs[i + j - 1][0];
                if(j == 0) dp[i % 2][j] = dp[(i - 1) % 2][j] + costs[i + j - 1][1];
                
                if(i > 0 && j > 0)
                    dp[i % 2][j] =  min(dp[i % 2][j - 1] + costs[i + j - 1][0], 
                                        dp[(i - 1) % 2][j] + costs[i + j - 1][1]);
            }
        }
        
        return dp[n % 2].back();
    }

    //---------- recursive solution, slow -----------
    
    /*
    int recurse(vector<vector<int>>& costs, int i, int cityA, int cityB){
        if(i == costs.size()) return 0;
        
        int costA = cityA > 0 ? costs[i][0] + recurse(costs, i + 1, cityA - 1, cityB) : INT_MAX;
        int costB = cityB > 0 ? costs[i][1] + recurse(costs, i + 1, cityA, cityB - 1) : INT_MAX;
        
        return min(costA, costB);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        return recurse(costs, 0, costs.size()/2, costs.size()/2);
    }
    */
};