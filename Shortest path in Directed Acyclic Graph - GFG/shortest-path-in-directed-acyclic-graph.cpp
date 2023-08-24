//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(int i,vector<pair<int,int> > adj[],stack<int>& s,vector<int>& vis){
        vis[i] =1;
        for(auto it : adj[i]){
            if(!vis[it.first]){
                topoSort(it.first,adj,s,vis);
            }
        }
        s.push(i);
    };
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        // BFS
        vector<pair<int,int> > adj[N];
        for(auto e : edges)
            adj[e[0]].push_back( {e[1], e[2]} );

        // vector<int> distance(N, INT_MAX);
        // distance[0] = 0;
    //     queue<int> q;
    //     q.push(0);
        
    //     while(q.size()){
    //         int node = q.front();   q.pop(); 

    //         for(auto padosi : adj[node]){
    //             int nbr = padosi[0] ;
    //             int dist = padosi[1];
    //             if(distance[node] + dist < distance[nbr]){
    //                 distance[nbr] = distance[node] + dist ;
    //                 q.push(nbr);
    //             }
    //         }
    //     }
    //     for(auto &a : distance)
    //         if(a==INT_MAX)a = -1;
    //     return distance;
    // }
    
        vector<int> vis(N,0);
        stack<int> s;
        for(int i=0;i < N; i++){
            if(!vis[i]){
                topoSort(i,adj,s,vis);
            }
        }
        
        // Relax the edges
        vector<int> dis(N,1e9);
        dis[0] =0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis[v]  > dis[node] + wt){
                    dis[v] = dis[node] + wt;
                }
            }
        }
        
        for(int i=0; i< N; i++){
            if(dis[i] == 1e9)dis[i] = -1;
        }
    
        return dis;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends