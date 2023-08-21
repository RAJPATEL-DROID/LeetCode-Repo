//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        if(matrix.size() == 1){
            return 0;
        }
        int ans=0;
        for(int i=0; i < matrix.size(); i++){
            int cnt = 0;
            for(int j =0 ; j< matrix[i].size();j++){
                
                if(matrix[i][j] == 0)continue;
                cnt =0;
                int r[] = {-1,-1,-1,0,1,1,1,0};
                int c[] = {-1,0,1,1,1,0,-1,-1};
                for(int k =0; k < 8 ;k++){
                    int row = i + r[k];
                    int col = j + c[k];
                    if(row >=0 && row < matrix.size() && col >= 0 && col < matrix[0].size() && matrix[row][col] == 0){
                        cnt++;
                    }
                }
                if(cnt % 2 == 0 && cnt != 0){
                    // cout<<i<<" "<<j<<" "<<cnt<<"\n";
                    ans++;
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends