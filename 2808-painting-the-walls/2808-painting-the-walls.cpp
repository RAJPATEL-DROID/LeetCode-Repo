class Solution {
public:
    // int n;
    // vector<vector<int>> dp;
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int  n  = cost.size();
        // dp = vector(n,vector(n+1,-1));
        // return solve(0,n,cost,time);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1;i <= n;i++){
            dp[n][i] = 1e9;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                int paint = cost[i] + dp[i + 1][max(0, remain - 1 - time[i])];
                int dontPaint = dp[i + 1][remain];
                dp[i][remain] = min(paint, dontPaint);
            }
        }

        return dp[0][n];
    }

    // int solve(int i,int remain,vector<int>& cost,vector<int>& time){
    //     if(remain <= 0){
    //         return 0;
    //     }

    //     if(i == n)return 1e9;

    //     if(dp[i][remain] != -1)return dp[i][remain];

    //     int paint = cost[i] + solve(i + 1,remain - 1-time[i], cost,time);
    //     int dontpaint = solve(i+1,remain,cost,time);
    //     dp[i][remain] = min(paint,dontpaint);
    //     return dp[i][remain];

    // }
};