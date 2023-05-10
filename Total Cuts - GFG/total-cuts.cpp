//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int> pref_sum(N);
        pref_sum[N-1] = A[N-1];
        for(int i = N-2;i >= 0; i--){
            pref_sum[i] = min(pref_sum[i+1],A[i]);
        }
        int maxi = A[0];
        int ans =0;
        for(int i=1;i < N;i++){
            if(maxi+pref_sum[i] >= K)ans++;
            maxi =max(maxi,A[i]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends