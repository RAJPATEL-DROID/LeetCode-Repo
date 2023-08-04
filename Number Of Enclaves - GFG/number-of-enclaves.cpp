//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int r,int c,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &vis){
      vis[r][c] = 1;
      vector<int> dir = {-1,0,1,0,-1};
      
      for(int i= 0; i< 4; i++){
          int row = r + dir[i];
          int col = c + dir[i+1];
          
          if(row >= 0 && row < n && col >=0 && col < m && grid[row][col] == 1 &&  vis[row][col] == 0){
              dfs(row,col,n,m,grid,vis);
          }
      }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int  n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i < n;i++){
            if(grid[i][0] == 1){
                dfs(i,0,n,m,grid,vis);
            }
            
            if(grid[i][m-1] == 1){
                dfs(i,m-1,n,m,grid,vis);
            }
        }
        
        for(int j=0;j < m;j++){
            if(grid[0][j] == 1){
                dfs(0,j,n,m,grid,vis);
            }
            
            if(grid[n-1][j] == 1){
                dfs(n-1,j,n,m,grid,vis);
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends