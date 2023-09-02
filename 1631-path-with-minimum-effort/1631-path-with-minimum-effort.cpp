class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] =0;
        pq.push({0,{0,0}});
        vector<int> dir = {-1,0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 && col == m-1)return dis;
            for(int i=0;i < 4; i++){
                int nr = row + dir[i];
                int nc = col + dir[i+1];
                
                if(nr >= 0 && nc >=0 && nr < n && nc < m){
                    int newEffort = max(dis,abs(heights[nr][nc] - heights[row][col]));
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        
        return 0;
    }
};