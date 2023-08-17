class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i < n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        int dir[5]={-1,0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int curr_dist = q.front().second;
            dis[row][col] = curr_dist;
            q.pop();
            for(int i=0;i < 4;i++){
                int r = row + dir[i];
                int c = col + dir[i+1];
                
                if( r >= 0 && c >= 0 && r < n && c < m && vis[r][c] == 0 ){
                    vis[r][c] =1;
                    q.push({{r,c},curr_dist + 1});
                } 
            }
        }
        
        return dis;
        
    }
};