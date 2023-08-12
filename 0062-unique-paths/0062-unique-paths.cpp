class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        dp[0][0] = 1;
        
        for(int i=0; i< n; i++){
            for(int j =0; j < m; j++){
                if(i == 0 && j ==0)dp[i][j] =1;
                else{
                    int left = 0,up =0;
                    if(i > 0)up = dp[i-1][j];
                    if(j > 0)left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};