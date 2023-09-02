//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first == destination.first && source.second == destination.second)return 0;
        
        queue<pair<int,pair<int,int>> > q;
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e9));
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        int dir[5] = {-1,0,1,0,-1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.second.first;
            int c = it.second.second;
            int dis =it.first;
            
            for(int i=0;i<4;i++){
                int newr = r + dir[i];
                int newc = c + dir[i+1];
                if(newr >=0 && newr < grid.size() && newc >=0 && newc < grid[0].size() && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc] ){
                    dist[newr][newc] = dis + 1;
                    if(newr  == destination.first && newc == destination.second)return dis+1;
                    q.push({dis+1,{newr,newc}});
                    
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends