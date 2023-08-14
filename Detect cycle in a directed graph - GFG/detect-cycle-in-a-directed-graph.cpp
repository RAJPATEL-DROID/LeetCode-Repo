//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private :
    bool dfs(int it,vector<int> adj[],int vis[],int pathVis[]){
        vis[it] = 1;
        pathVis[it] = 1;
        
        for(auto i: adj[it]){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis) == true)return true;
            } else if(pathVis[i])return true;
        }
        
        pathVis[it] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        
        int pathVis[V] = {0};
        
        for(int it=0;it < V; it++){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis) == true)return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends