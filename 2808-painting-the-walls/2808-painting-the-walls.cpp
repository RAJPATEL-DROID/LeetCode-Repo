class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int paintWalls(vector<int>& cost, vector<int>& time) {
         n  = cost.size();
        dp = vector(n,vector(n+1,-1));
        return solve(0,n,cost,time);
    }

    int solve(int i,int remain,vector<int>& cost,vector<int>& time){
        if(remain <= 0){
            return 0;
        }

        if(i == n)return 1e9;

        if(dp[i][remain] != -1)return dp[i][remain];

        int paint = cost[i] + solve(i + 1,remain - 1-time[i], cost,time);
        int dontpaint = solve(i+1,remain,cost,time);
        dp[i][remain] = min(paint,dontpaint);
        return dp[i][remain];

    }
};