//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod=1e9+7;
    int solve(int i,int n,int x,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(pow(i,x)>n) return 0;
        if(dp[i][n]!=-1) return dp[i][n];
        int ntake=solve(i+1,n,x,dp);
        int take=0;
        if(pow(i,x)<=n) take=solve(i+1,n-pow(i,x),x,dp);
        return dp[i][n]=(take+ntake)%mod;
    }
    int numOfWays(int n, int x){
        vector<vector<int>>dp(n+2,vector<int>(n+1,-1));
        return solve(1,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends