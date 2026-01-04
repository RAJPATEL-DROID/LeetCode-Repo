class Solution {
public:
//     int dp[5001][4][4][4] = {};
//     int numOfWays(int n) {
//         return dfs(n,0,0,0);
//     }

//     int dfs(int n, int a0,int b0,int c0){
//         if(n == 0)return 1;

//         if(dp[n][a0][b0][c0] != 0 )return dp[n][a0][b0][c0];

//         int ans = 0;

//         vector<int> colors ={1,2,3};

//         for(int a: colors){
//             if(a == a0)continue;
//             for(int b : colors){
//                 if( b == b0 || b == a)continue;
//                 for(int c : colors){
//                     if(c == c0 || c == b)continue;
//                     ans += dfs(n-1,a,b,c);
//                     ans %= 10^7;
//                 }
//             }
//         }

//         return dp[n][a0][b0][b0] = ans;
//     }
// };
    int numOfWays(int n){
        const int MOD = 1000000007;
        // Type x (Alternating): 6 patterns (first and last column same)
        // Type y (All Different): 6 patterns (all three columns different)
        long long x = 6, y = 6;

        for (int i = 2; i <= n; i++) {
            // x (Alternating) → next row: Can form 3 Alternating + 2 All Different patterns
            // y (All Different) → next row: Can form 2 Alternating + 2 All Different patterns
            long long new_x = (3 * x + 2 * y) % MOD;
            long long new_y = (2 * x + 2 * y) % MOD;
            x = new_x;
            y = new_y;
        }

        return (x + y) % MOD;
    }
};