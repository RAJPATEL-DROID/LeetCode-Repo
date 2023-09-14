//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
// 	int solve(int arr[], int n, int sum){
// 	    if(n == 0 && sum == 0)return 1;
//         if(n == 0)return 0;
//         if(sum == 0)return 1;
        
//         if(arr[n-1] > sum){
//             return perfectSum(arr,n-1,sum);
//         }else{
//             return perfectSum(arr,n-1,sum-arr[n-1]) + perfectSum(arr,n-1,sum);
//         }
// 	}
    int mod = 1e9 + 7;
    int solve(int index,int target,int arr[],int n,vector<vector<int>>& dp){
        if(index == -1)return target == 0 %mod;
        if(dp[index][target] != -1)return dp[index][target]%mod;
        int notPick = solve(index-1,target,arr,n,dp)%mod;
        
        int pick = 0;
        
        if(target >= arr[index])pick = solve(index-1,target-arr[index],arr,n,dp)%mod;
        
        return dp[index][target] = (pick%mod + notPick%mod)%mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        // Recursion TLE
        // sort(arr,arr+n,greater<int>());
        // return solve(arr,n,sum);
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,n,dp)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends