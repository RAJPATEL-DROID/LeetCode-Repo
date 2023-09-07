class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<>> pq;
        pq.push({0,0});
        
        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        long mod = 1e9+ 7;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node= it.second;
            long long t = it.first;
            if(t > dist[node])continue;
            for(auto itr : adj[node]){
                int adjNode = itr.first;
                long long adjtime = itr.second;
                
                if(t + adjtime < dist[adjNode]){
                    ways[adjNode] = ways[node] % mod;
                    dist[adjNode] = t + adjtime;
                    pq.push({dist[adjNode], adjNode});
                }else if(t + adjtime == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
};