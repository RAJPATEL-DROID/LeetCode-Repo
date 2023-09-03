class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>> >   q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int stop = it.first;
            int currStation = it.second.first;
            int cost = it.second.second;
            
            if(stop > k)continue;
            
            for(auto itr : adj[currStation]){
                int adjNode  = itr.first;
                int costNode = itr.second;
                
                if(cost + costNode < dist[adjNode] && stop <= k){
                    dist[adjNode] = cost + costNode;
                    q.push({stop + 1, {adjNode,dist[adjNode]}});
                }
            }
        }
        
        if(dist[dst] == 1e9)return -1;
        return dist[dst];
    }
};