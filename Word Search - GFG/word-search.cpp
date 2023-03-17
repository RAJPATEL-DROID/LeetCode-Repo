//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool search(int i ,int j,int n,int m,vector<vector<char>>& board, string word,int currSize){
        if(currSize == word.size())return true;
        if(i <0 || j <0 || i == n || j == m || board[i][j] != word[currSize]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool c1 = search(i+1,j,n,m,board,word,currSize+1);
        bool c2 = search(i,j+1,n,m,board,word,currSize+1);
        bool c3 = search(i-1,j,n,m,board,word,currSize+1);
        bool c4 = search(i,j-1,n,m,board,word,currSize+1);
        board[i][j] = temp;
        
        return c1 || c2 || c3 || c4;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();int m = board[0].size();
        for(int i=0;i < n;i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(search(i,j,n,m,board,word,0))return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends