class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i <n; i++){
            for(int j=0; j< m ; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> dir = {-1,0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            dis[row][col] = step;
            q.pop();
            
            for(int i=0;i< 4; i++){
                int x = row + dir[i];
                int y = col + dir[i+1];
                
                if(x>=0 && x < n && y >=0 && y < m && 
                  vis[x][y] == 0){
                    vis[x][y] =1;
                    q.push({{x,y},step+1});
                }
            }
        }
        
        return dis;
    }
};