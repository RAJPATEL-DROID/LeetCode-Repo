//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod = 100000;
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        if(start == end)return 0;
        
        int n= arr.size();
        vector<int> vis(mod,-1);
        
        vis[start] =0;
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int i=0;i < n;i++){
                long long next = (1ll*curr*arr[i])%mod;
                
                if(vis[next] == -1){
                    vis[next] = vis[curr] + 1;
                    q.push(next);
                    if(next == end)return vis[next];
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends