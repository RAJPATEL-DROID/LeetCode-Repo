//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        // Code here
        vector<vector<int>> v(n,vector<int>(m,0));
        int ro[]={-1,0,1,0};
        int co[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0 && mat[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1))
                {
                    queue<pair<int,int > > q;
                    q.push({i,j});
                    v[i][j]=1;
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int nx=x+ro[k];
                            int ny=y+co[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && v[nx][ny]==0)
                            {
                                    v[nx][ny]=1;
                                    q.push({nx,ny});
                            }
                        }
                   }
                }
            }
        }
        int as=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0 && mat[i][j]==1)
                {
                    as++;
                    queue<pair<int,int > > q;
                    q.push({i,j});
                    v[i][j]=1;
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int nx=x+ro[k];
                            int ny=y+co[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && v[nx][ny]==0)
                            {
                                    v[nx][ny]=1;
                                    q.push({nx,ny});
                            }
                        }
                   }
                }
            }
        }
        return as;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends