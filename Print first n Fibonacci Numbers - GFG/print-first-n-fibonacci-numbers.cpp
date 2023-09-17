//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    void solve(int ind,vector<long long>& ans,int n){
        if(ind == n){
            return;
        }
        ans[ind] = ans[ind-1] + ans[ind-2];
        solve(ind+1,ans,n);
        return;
    }
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> ans(n);
        if(n==1)return {1};
        if(n==2)return {1,1};
        ans[0] =1;
        ans[1] = 1;
        
        solve(2,ans,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends