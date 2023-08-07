class Solution {
public:
    void solve(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        vis[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n= grid.size();
        int m = grid[0].size();
        vector<int> dir = {-1,0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0 ; i <4; i++){
                    int nrow =  r + dir[i];
                    int ncol = c + dir[i+1];
                    if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m &&
                      grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = true;
                        q.push({nrow,ncol});
                    }
                }            
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i< n;i++){
            for(int j=0;j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    solve(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};