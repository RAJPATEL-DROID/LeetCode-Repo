//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        string str = "balloon";
        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }
        int mini =INT_MAX;
        for(char c:str){
            if(c=='b' || c=='a' || c=='n') mini = min(mini,m[c]);
            else
                mini = min(mini,m[c]/2);
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends