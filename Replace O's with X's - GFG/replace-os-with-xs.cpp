//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,int n,int m,vector<vector<char>>& mat,vector<vector<int>>& vis){
        vis[row][col] = 1;
        vector<int> dir = {-1,0,1,0,-1};
        for(int i=0; i< 4; i++){
            int x = row + dir[i];
            int y = col + dir[i+1];
            
            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && mat[x][y] == 'O'){
                dfs(x,y,n,m,mat,vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int j=0; j < m; j++){
            
            // first row;
            if(!vis[0][j] && mat[0][j] == 'O')
                dfs(0,j,n,m,mat,vis);
                
            // last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
                dfs(n-1,j,n,m,mat,vis);
        }
        
        
        for(int i=0;i < n; i++){
            
            // first column
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i,0,n,m,mat,vis);
            }
            
            //last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i,m-1,n,m,mat,vis);
            }
        }
        
        for(int i=0; i< n; i++){
            for(int j=0; j < m;j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends