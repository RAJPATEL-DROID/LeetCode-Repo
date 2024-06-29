class Solution {
public:

    void dfs(int curNode,unordered_map<int,vector<int>>& adj, vector<bool>& vis){
        vis[curNode] = true;

        for(int& i : adj[curNode]){
            if(vis[i] != true){
                dfs(i,adj,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result;;
        unordered_map<int,vector<int>> adj;

        for(auto &vec : edges){
            int u= vec[0];
            int v = vec[1];
            adj[v].push_back(u);
        }

        for(int i =0; i< n; i++){
            vector<int> parents;
            vector<bool> visited(n,false);

            dfs(i,adj,visited);

            for(int j=0; j < n; j++)
            {
                if(j == i)continue;
                if(visited[j] == true){
                    parents.push_back(j);
                }
            }

            result.push_back(parents);
        }

        return result;
    }
};