class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // Floy Warshall Algo
//         vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
	    
// 	    for(auto it : edges){
//             matrix[it[0]][it[1]] = it[2];
//             matrix[it[1]][it[0]] = it[2];
//         }
// 	    for(int i=0;i < n;i++)matrix[i][i] =0;
        
// 	    for(int k=0; k < n;k++){
// 	        for(int i=0;i < n;i++){
// 	            for(int j=0;j < n; j++){
// 	                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)continue;
// 	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
// 	            }
// 	        }
// 	    }
        
        int cityCnt = n;
        int city = -1;
//         for(int i=0;i <n;i++){
//             int cnt =0;
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j] <= distanceThreshold)cnt++;
//             }
            
//             if(cnt <= cityCnt){
//                 city = i;
//                 cityCnt = cnt;
//             }
//         }
        
//         return city;
        
        
        
        vector<pair<int,int>> adj[n];
        
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        for(int i=0;i< n;i++){
            vector<int> dist(n,1e9);
            dist[i]=0;
            pq.push({0,i});
            
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int city = it.second;
                int wt = it.first;
                
                for(auto itr: adj[city]){
                    int adjNode = itr.first;
                    int adjWt = itr.second;
                    if(wt + adjWt < dist[adjNode]){
                        dist[adjNode] = wt + adjWt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
            int cnt =0;
            for(int k=0; k < n; k++){
                if(dist[k] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= cityCnt){
                cityCnt = cnt;
                city = i;
            }
        }
        return city;
    }
};