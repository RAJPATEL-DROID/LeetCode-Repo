//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int i,vector<int> adj[],int vis[],int pathVis[]){
      pathVis[i] = 1;
      vis[i] = 1;
      
      for(int it:adj[i]){
          if(!vis[it]){
              if(dfs(it,adj,vis,pathVis))return true;
          }else if(pathVis[it])return true;
      }
      pathVis[i] = 0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        int vis[V] = {0};
        
        int pathVis[V] = {0};
        
        for(int i=0;i < V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis))return true;
            }
        } 
         return false;
        
        
        // BFS - Using Kahn Algo
        // int inDegree[V] = {0};
        
        // for(int i=0;i<V;i++){
        //     for(auto it : adj[i]){
        //         inDegree[it]++;
        //     }
        // }
        
        // queue<int> q;
        // for(int i=0;i<V;i++){
        //     if(inDegree[i] == 0)q.push(i);
        // }
        
        // int cnt=0;
        
        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();
        //     cnt++;
            
        //     for(auto it: adj[node]){
        //         inDegree[it]--;
        //         if(inDegree[it] == 0)q.push(it);
        //     }
        // }
        
        // return !(cnt == V);
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