class Solution {
public:
    int solve(int n,vector<int>& dp){

        if(n == 0)return 1;
        if(n < 0)return 0;

        if(dp[n] != - 1){
            return dp[n];
        }

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        int prev1 = 1;
        int prev2 = 1;

        // solve(n,dp);
        // return dp[n];

        for(int i=2; i <= n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }    

        return prev1;

    }
};