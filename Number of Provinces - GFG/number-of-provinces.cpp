//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int curr_vertex,vector<bool>& vis,vector<vector<int>>& adj){
      int n = adj.size();
      vis[curr_vertex] = true;
      
      for(int i=0; i < n; i++){
          if(i == curr_vertex)continue;
          
            if(!vis[i] && adj[curr_vertex][i] == 1){
                dfs(i,vis,adj);        
            }
      }
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int ans =0;
        vector<bool> vis(V,false);
    
        for(int i=0; i < V; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends