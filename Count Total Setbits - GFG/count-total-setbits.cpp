//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long n) {
        // code here
        // long long cnt =0;
        // for(long long i= 1;i <= N;i++){
        //     cnt += __builtin_popcount(i);
        // }
        // return cnt;
        
        if(n<=1)return n;
        int x = log2(n);
        return (x*pow(2,x-1) + (n-pow(2,x) + 1) + countBits(n - pow(2,x)) );
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends