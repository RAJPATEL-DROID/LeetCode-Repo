//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Memoization
    //  long long int dfs(int S[], int m, int n,vector<vector<long long>>& dp){
    //     if(n == 0)
    //         return 1;
    //     if(n <  0 || m <= 0)
    //         return 0;
            
    //     if(dp[m][n]){
    //         return dp[m][n];
    //     }
    //     return dp[m][n] = dfs(S, m-1, n,dp) + dfs(S, m, n-S[m-1],dp);
    // }
    long long int count(int S[], int m, int n) {
        // code here.
        // vector<vector<long long>> dp(N+1,vector<long long>(sum+1,0));
        // return dfs(coins,N,sum,dp);
        
        vector <long long int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=0; i<m; i++)
            for(int j=S[i]; j<=n; j++)
                dp[j] += dp[j-S[i]];
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends