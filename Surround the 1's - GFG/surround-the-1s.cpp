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
                if(matrix[i][j] == 1){
                    if(i >= 1 && matrix[i-1][j] == 0){
                        cnt++;
                    }   
                    if(j >= 1 && matrix[i][j-1] == 0){
                        cnt++;
                    }
                    if(i < matrix.size()-1 && matrix[i+1][j] == 0){
                        cnt++;
                    }
                    if(j < matrix[i].size()-1 && matrix[i][j+1] == 0){
                        cnt++;
                    }
                    if(i >= 1 && j >=1 && matrix[i-1][j-1] == 0){
                        cnt++;
                    }
                    if(i < matrix.size()-1  && j < matrix[i].size()-1 && matrix[i+1][j+1] == 0){
                        cnt++;
                    }
                    if(i >= 1 && j < matrix[i].size()-1 && matrix[i-1][j+1] == 0){
                        cnt++;
                    }
                    if(j >= 1 && i < matrix.size()-1  &&  matrix[i+1][j-1] == 0){
                        cnt++;
                    }
                }
                if(cnt % 2 == 0 && cnt != 0){
                    // cout<<i<<" "<<j<<" "<<cnt<<"\n";
                    ans++;
                }
                    cnt=0;
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