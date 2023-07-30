//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(vector<int> adj[] ,int curr,int parent,vector<int>& vis){
        vis[curr] = 1;
        for(int i=0; i< adj[curr].size(); i++){
            if(!vis[ adj[curr][i] ]){
                if(bfs(adj,adj[curr][i],curr,vis)){
                    return true;
                }
            }else if(parent != adj[curr][i]){
                    return true;
            }
        }
        
        return false;
    };
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i< V; i++){
            if(vis[i] == 0){
                if(bfs(adj,i,-1,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends