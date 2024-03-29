//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if( (N > 1 && S== 0) || (S > 9*N) ){
            return "-1";
        }
        string ans="";
        for(int i=0;i <S/9;i++){
            ans +='9';
        }
        if(S%9)ans+='0' + S%9;
        while(ans.size() != N)ans+='0';
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends