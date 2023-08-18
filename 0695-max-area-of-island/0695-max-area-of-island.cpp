class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        vis[i][j] = true;
        int area=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        area++;
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
                      grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        area++;
                        vis[nrow][ncol] = true;
                        q.push({nrow,ncol});
                    }
            }            
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int area=0,ans=0;
        for(int i=0;i< n;i++){
            for(int j=0;j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    area = solve(i,j,grid,vis);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};