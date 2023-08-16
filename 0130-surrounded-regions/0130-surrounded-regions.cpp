class Solution {
public:
    void dfs(int r,int c,int n,int m,vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[r][c] =1;
        vector<int> dir = {-1,0,1,0,-1};
        for(int i=0; i < 4; i++){
            int row = r + dir[i];
            int col = c + dir[i+1];
            
            if(row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] &&
              board[row][col] == 'O'){
                dfs(row,col,n,m,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m = board[0].size();
           vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i< n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i,0,n,m,board,vis);
            }
            
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i,m-1,n,m,board,vis);
            }
            
        }
        
        for(int j=0; j< m; j++){
            
            if(!vis[0][j] && board[0][j] =='O'){
                dfs(0,j,n,m,board,vis);
            }
            
            if(!vis[n-1][j] && board[n-1][j] =='O'){
                dfs(n-1,j,n,m,board,vis);
            }
        }
        
        for(int i=0; i< n; i++){
            for(int j=0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O')board[i][j] ='X';
            }
        }
    }
};