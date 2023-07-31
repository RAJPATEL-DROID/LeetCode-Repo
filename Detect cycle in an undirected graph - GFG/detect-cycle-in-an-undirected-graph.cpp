//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> adj[] ,int curr,int parent,vector<int>& vis){
        vis[curr] = 1;
        for(int i=0; i< adj[curr].size(); i++){
            if(!vis[ adj[curr][i] ]){
                if(dfs(adj,adj[curr][i],curr,vis)){
                    return true;
                }
            }else if(parent != adj[curr][i]){
                    return true;
            }
        }
        
        return false;
    };
    
    bool bfs(vector<int> adj[] ,int j,vector<int>& vis){
        queue<int> q;
        q.push(j);
        while(!q.empty()){
            int curr =q.front();
            q.pop();
            if(vis[curr] == 1)return true;
            
            vis[curr] = 1;
            for(auto it : adj[curr]){
                // int conn = adj[curr][i];
                if(vis[it] == 1)continue;
                q.push(it);
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i< V; i++){
            if(vis[i] == 0){
                // if(dfs(adj,i,-1,vis)){
                if(bfs(adj,i,vis)){
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