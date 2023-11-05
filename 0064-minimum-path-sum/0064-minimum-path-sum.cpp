class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int dp[n][m];
        dp[0][0] = grid[0][0];

        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(i == 0 && j == 0)continue;
                else{
                    int left = INT_MAX,up= INT_MAX;
                    if(j > 0)left = min(left,grid[i][j] + dp[i][j-1]);
                    if(i > 0)up = min(up, grid[i][j] + dp[i-1][j]);
                    dp[i][j] = min(left,up);
                }
                
            }
        }

        return dp[n-1][m-1];
    }
};