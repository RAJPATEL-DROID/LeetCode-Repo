//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string,int> m;

        for(int i=0; i < n; i++){
           m[arr[i]]++;           
        }
        int cnt=0;
        for(auto i :m){
            string temp = i.first;
            reverse(temp.begin(),temp.end());
            
            if(i.first == temp){
                if(i.second%2){
                    cnt++;
                }
                if(cnt>1)return false;
            }
            else{
                if(i.second != m[temp])return false;
            }
        }
    return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends