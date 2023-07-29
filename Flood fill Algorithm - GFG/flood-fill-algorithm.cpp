//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ini=image[sr][sc];
        image[sr][sc] = newColor;
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        vector<int> dir = {-1,0,1,0,-1};
        
        vis[sr][sc] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                
                for(int i=0;i < 4; i++){
                    int r = p.first  + dir[i];
                    int c = p.second + dir[i+1];
                    
                    if(r>= 0 && r < n && c>=0 && c< m && image[r][c] == ini && vis[r][c] == 0){
                        vis[r][c]= 1;
                        image[r][c] = newColor;
                        q.push({r,c});
                    }
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends