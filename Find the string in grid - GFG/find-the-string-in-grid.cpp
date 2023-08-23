//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,0},{1,1},{0,1}};
    bool solve(int i,int j,vector<vector<char>> grid,string word){
        
        for(auto it : dir){
            int x = i;
            int y = j;
            int cnt =0;
            
            while(x >=0 && x < grid.size() && y >= 0 && y < grid[0].size() && cnt < word.length() && 
            grid[x][y] == word[cnt]){
                x = x + it[0];
                y = y + it[1];
                cnt++;
            }
            
            if(cnt == word.length()){
                return true;
            }
        }
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j] == word[0] && solve(i,j,grid,word ) ) {
	                    ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends