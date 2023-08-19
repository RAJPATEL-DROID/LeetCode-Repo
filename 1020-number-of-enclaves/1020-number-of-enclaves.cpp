class Solution {
public:
//      void dfs(int r,int c,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &vis){
//       vis[r][c] = 1;
//       vector<int> dir = {-1,0,1,0,-1};
      
//       for(int i= 0; i< 4; i++){
//           int row = r + dir[i];
//           int col = c + dir[i+1];
          
//           if(row >= 0 && row < n && col >=0 && col < m && grid[row][col] == 1 &&  vis[row][col] == 0){
//               dfs(row,col,n,m,grid,vis);
//           }
//       }
//   }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int  n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i < n;i++){
            if(grid[i][0] == 1){
                // dfs(i,0,n,m,grid,vis);
                q.push({i,0});
                vis[i][0] =1;
            }
            
            if(grid[i][m-1] == 1){
                // dfs(i,m-1,n,m,grid,vis);
                q.push({i,m-1});
                vis[i][m-1] =1;
            }
        }
        
        for(int j=0;j < m;j++){
            if(grid[0][j] == 1){
                // dfs(0,j,n,m,grid,vis);
                q.push({0,j});
                vis[0][j] =1;
            }
            
            if(grid[n-1][j] == 1){
                // dfs(n-1,j,n,m,grid,vis);
                q.push({n-1,j});
                vis[n-1][j] =1;
            }
        }
        
        vector<int> dir  = {-1,0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i < 4;i++){
                int row = r + dir[i];
                int col = c + dir[i + 1];
                
                if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1 && !vis[row][col]){
                    q.push({row,col});
                    vis[row][col] = 1;
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i < n; i++){
            for(int j=0; j <m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};