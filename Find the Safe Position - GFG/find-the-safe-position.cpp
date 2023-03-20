//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void func(vector<int> v,int& ans,int k,int ind){
        if(v.size() == 1){
            ans =  v[0];
            return;
        }    
        
        ind = (ind+k)%v.size();
        v.erase(v.begin()+ind);
        func(v,ans,k,ind);
    }
    int safePos(int n, int k) {
        // code here
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i); 
        }
        int ans =-1;
        int ind =0;
        func(v,ans,k-1,0);
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends