class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }
    
    void bfs(int node,vector<vector<int>>& isConnected,vector<bool>& vis){
        queue<int> q;
        q.push(node);
        vis[node] = true;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            
            for(int i=0;i < isConnected.size(); i++){
                if(isConnected[node][i] && !vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                // dfs(i, isConnected, visit);
                bfs(i, isConnected, visit);

            }
        }

        return numberOfComponents;
    }
};