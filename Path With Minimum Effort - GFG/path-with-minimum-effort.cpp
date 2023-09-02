//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        vector<int> dir = {-1,0,1,0,-1};
        dist[0][0] =0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int row =it.second.first;
            int col =it.second.second;
            int dis =it.first;
            
            if(row == n-1 && col == m-1)return dis;
            for(int i=0;i < 4;i++){
                int nr = row + dir[i];
                int nc = col + dir[i+1];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m ){
                    int newEffort =max(dis,abs( heights[row][col] - heights[nr][nc]));
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                } 
            }
            
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends