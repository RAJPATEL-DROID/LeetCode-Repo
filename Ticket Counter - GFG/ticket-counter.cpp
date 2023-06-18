//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        // code here
        // int m = N/K;
        // int r = N%K;
        
        // if(m%2 == 0 && !r )return K*(m/2) +1;
        // if(m%2 == 0 && r )return K*(m/2)+ r;
        // if(m%2 != 0 && !r )return K*(m/2 + 1 );
        // if(m%2 != 0 && r )return K*(m/2 + 1)+ 1;
        
         int l=1,r=n,f=1;
        while(l<=r){
            if(f){
                if(l+k<r)l+=k;
                else return r;
            }
            else{
                if(r-k>l)r-=k;
                else return l;
            }
            f=!f;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends