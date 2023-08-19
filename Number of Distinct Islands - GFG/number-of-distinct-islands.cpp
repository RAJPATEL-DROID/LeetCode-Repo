//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void solve(vector<vector<int>>& grid,int i,int j,string& path,char c){
      if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j]) return;
      grid[i][j] = 0;
      path.push_back(c);
      solve(grid,i-1,j,path,'U');
      solve(grid,i+1,j,path,'D');
      solve(grid,i,j-1,path,'L');
      solve(grid,i,j+1,path,'R');
      path.push_back('X');
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        unordered_set<string> st;
        for(int i=0;i< grid.size(); i++){
            for(int j=0;j< grid[0].size();j++){
                if(grid[i][j]){
                    string v;
                    solve(grid,i,j,v,'S');
                    st.insert(v);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends