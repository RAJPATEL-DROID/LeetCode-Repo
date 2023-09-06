//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    
    void dfs(int i,set<int>& s,vector<int> adj[],vector<int>& vis){
        vis[i] = 1;
        for(int it : adj[i]){

                if(s.find(it) != s.end())continue;
                s.insert(it);
                dfs(it,s,adj,vis);
        }
    }
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    set<int> s;
	    vector<int> vis(V,-1);
	    for(int i=0;i< V;i++){
	        if(vis[i] == -1){
	            s.insert(i);
	            dfs(i,s,adj,vis);
	            if(s.size() == V)return i;
	            s.clear();    
	        }
	        
	    }
	    
	    return -1;
	     
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends