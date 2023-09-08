//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
        // vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
	    
	   // for(auto it : edges){
    //         matrix[it[0]][it[1]] = it[2];
    //         matrix[it[1]][it[0]] = it[2];
    //     }
	   // for(int i=0;i < n;i++)matrix[i][i] =0;
        
	   // for(int k=0; k < n;k++){
	   //     for(int i=0;i < n;i++){
	   //         for(int j=0;j < n; j++){
	   //             if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)continue;
	   //             matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	   //         }
	   //     }
	   // }
        
        int cityCnt = n;
        int city = -1;
    //     for(int i=0;i <n;i++){
    //         int cnt =0;
    //         for(int j=0;j<n;j++){
    //             if(matrix[i][j] <= distanceThreshold)cnt++;
    //         }
            
    //         if(cnt <= cityCnt){
    //             city = i;
    //             cityCnt = cnt;
    //         }
    //     }
        
    //     return city;
               
       vector<pair<int,int> > adj[n];
      
        for(auto it : edges){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        for(int k=0; k < n; k++){
            vector<int> dist(n,1e9);
            dist[k] =0;
            pq.push({0,k});
            
            while(!pq.empty())
            {
                auto it = pq.top();
                pq.pop();
                
                int city =it.second;
                int wt = it.first;
                
                for(auto itr: adj[city]){
                    int adjCity = itr.first;
                    int adjWt = itr.second;
                    
                    if(wt + adjWt < dist[adjCity]){
                        dist[adjCity]  = wt + adjWt;
                        pq.push({dist[adjCity],adjCity});
                    }
                }
            }
            
            int cnt =0;
            
            for(int i=0; i < n; i++){
                if(dist[i] <= distanceThreshold)cnt++;
            }
            
            if(cnt <= cityCnt){
                cityCnt = cnt;
                city = k;
            }
        }
        
        return city;
       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends