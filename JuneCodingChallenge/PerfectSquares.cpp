class Solution {
public:
    int min(int a, int b) { return a < b ? a : b; }

    int numSquares(int n){
        vector<int> sum(n, INT_MAX);

        for(int i = 1; i < sum.size(); ++i){
            for(int j = 1; j*j < n && j*j <= i; ++j){
                if(i == j*j) 
                    sum[i - 1] = 1;
                else 
                    sum[i - 1] = min(sum[i - 1], sum[i - j*j - 1] + 1);
            }
        }

        return sum.back();
    }

};