class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n == 0)return 1;
        if(n == 1)return 1;

        if(dp[n] != -1)return dp[n];
        int onlyOne = solve(n-1);
        int twoStair = solve(n-2);

        return dp[n] = onlyOne + twoStair;
    }
    
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0] =1;
        dp[1] =0;
        return solve(n);
    }
};