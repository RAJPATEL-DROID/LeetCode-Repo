class Solution {
public:
unordered_map<int,vector<int>> graph;

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto& edge : adjacentPairs){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }        

        int root =0;
        for(auto& pair : graph){
            if(pair.second.size() == 1){
                root = pair.first;
                break;
            }
        }

        vector<int> ans = {root};
        // dfs(root,INT_MAX,ans);
        // return ans;

        int curr = root;
        int prev = INT_MAX;
        while(ans.size() < graph.size()){
            for(int n : graph[curr]){
                if(n != prev){
                    ans.push_back(n);
                    prev = curr;
                    curr = n;
                    break;
                }
            }
        }

        return ans;

    }

    void dfs(int node,int prev,vector<int>& ans){
        ans.push_back(node);

        for(int n : graph[node]){
            if(n != prev){
                dfs(n,node,ans);
            }
        }
    }
};