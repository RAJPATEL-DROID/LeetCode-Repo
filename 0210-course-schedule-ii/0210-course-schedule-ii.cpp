class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        vector<int> adj[V];
	    
	    for(auto it: pre){
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    vector<int>indegree(V,0);
        
	    for(int i=0;i < V; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i< V; i++){
	        if(indegree[i] == 0)q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(int i : adj[node]){
	            indegree[i]--;
	            if(indegree[i] == 0)q.push(i);
	        }
	        ans.push_back(node);
	    }
	    
	    if(ans.size() == V)return ans;
	    return {};
    }
};