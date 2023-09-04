//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int,int>> adj[n+1];
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k] =0; 
        
        pq.push({0,k});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
            
            for(auto neighbour : adj[node]){
                if(dist[neighbour.first] > dist[node] + neighbour.second){
                    dist[neighbour.first] = dist[node] + neighbour.second;
                    pq.push({dist[neighbour.first], neighbour.first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9)return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends