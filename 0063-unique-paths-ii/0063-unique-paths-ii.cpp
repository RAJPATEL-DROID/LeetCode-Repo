class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n,int m ,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(n == 0 && m == 0){
            if(grid[n][m])return dp[n][m] =0;
            return dp[n][m]=1;
        }
        if(dp[n][m] != -1)return dp[n][m];
        int left=0;
        int up =0;
        if(n > 0 && !grid[n-1][m])left = solve(n-1,m,grid,dp);
        if(m > 0 && !grid[n][m-1])up = solve(n,m-1,grid,dp);

        return dp[n][m] = (left + up);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1] == 1)return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};