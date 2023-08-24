//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
  public:
    // void dfs(int i,vector<int> adj[],vector<int>& dis,vector<int>& vis){
    //     vis[i] = 1;
    //     for(auto node :adj[i]){
    //         if(dis[node] > dis[i] + 1){
    //             dis[node] = dis[i] + 1;
    //         }
    //         if(!vis[node])
    //             dfs(node,adj,dis,vis);
    //     }
    //     vis[i] =0;
    // }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dis(N,1e9);  // ,vis(N);
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(dis[it] > dis[node] + 1){
                    q.push(it);
                    dis[it] = dis[node] + 1;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i] == 1e9)dis[i] = -1;
        }
        return dis;
        // dfs(src,adj,dis,vis);
        // for(auto it : dis){
        //     if(dis[it] == 1e9)dis[it] = -1;
        // }
        // return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends