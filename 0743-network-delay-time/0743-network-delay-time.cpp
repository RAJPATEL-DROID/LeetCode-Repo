class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,k});
        
        vector<int> time(n+1,1e9);
        time[k] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int tm = it.first;
            
            for(auto itr: adj[node]){
                int t = itr.second;
                int adjNode = itr.first;
                if(tm  + t < time[adjNode]){
                    time[adjNode] = tm + t;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=1;i<= n;i++){
            ans = max(ans,time[i]);
            cout<<ans<<" "<<i<<" "<<time[i]<<"\n";
        }
        
        if(ans == 1e9)return -1;
        return ans;
        
        
    }
};