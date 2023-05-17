//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int L=0,R=0,D=0,U=0,i=0;
        while(i != s.size()){
            if(s[i] == 'L'){L++; if(R != 0)R--;}
            else if(s[i] == 'R'){R++; if(L != 0)L--;}
            else if(s[i] == 'D'){D++;if(U != 0)U--;}
            else {U++;if(D != 0)D--;}
            i++;
            if(L >=m|| R>=m  || U >=n || D >= n)return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends