//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 || A[X][Y] == 0)return -1;
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue<pair<pair<int,int>,int> > q;
        q.push({{0,0},0});
        vis[0][0] =1;
        
        int dis[5] = {-1,0,1,0,-1};
        
        int ans = N*M +1; // max steps can be N*M
    
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                if(r == X && c == Y){
                    return steps;
                }
                
                for(int i=0; i< 4;i++){
                    int rn = r + dis[i];
                    int cn = c + dis[i+1];
                    if(rn >= 0 && rn < N && cn >= 0 
                        && cn < M && A[rn][cn] && !vis[rn][cn]){
                    // cout<<rn<<" "<<cn<<" "<<A[rn][cn]<<"\n";
                            q.push({{rn,cn},steps+1});
                            vis[rn][cn] =1;
                    }
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends