class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> graph;
        vector<int> indegree(n,0);

        for(auto edge: relations){
            int x = edge[0] -1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
            indegree[y]++;
        }

        queue<int> q;
        vector<int> maxtime(n,0);

        for(int node=0;node<n;node++){
            if(indegree[node] ==0){
                q.push(node);
                maxtime[node] = time[node];
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:graph[node]){
                maxtime[it] = max(maxtime[it],maxtime[node] + time[it]);
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        int ans =0;
        for(auto it : maxtime){
            ans = max(it,ans);
        }
        return ans;
    }
};