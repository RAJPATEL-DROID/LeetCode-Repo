//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int Solve(int arr[],int n,int i,int target,int sum, vector<vector<int>>&dp){
         if(i>=n||sum>target)return 0;
         if(sum==target){
             return 1;
         }
         if(dp[i][sum]!=-1){
             return dp[i][sum];
         }
         int inclusion=Solve(arr,n,i+1,target,sum+arr[i],dp);
          int exclusion=Solve(arr,n,i+1,target,sum+0,dp);
          return dp[i][sum]=inclusion||exclusion;
    }
    int equalPartition(int N, int arr[])
    {
        int target=0;
        for(int i=0;i<N;i++){
            target+=arr[i];
        }
        if(target%2==0){
            vector<vector<int>>dp(N,vector<int>(target+1,-1));
            return Solve(arr,N,0,target/2,0,dp);
        }
      return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends