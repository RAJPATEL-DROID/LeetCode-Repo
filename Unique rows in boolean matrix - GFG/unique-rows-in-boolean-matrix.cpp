//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int a[MAX][MAX],int r,int c)
    {
        //Your code here
        
        // BRUTE_FOCRCE SC(R*C)
        // set<vector<int>> s;
        // vector<vector<int> >ans;
        
        // for(int i=0;i< row;i++){
        //     vector<int> temp;
        //     for(int j=0;j<col;j++){
        //         temp.push_back(M[i][j]);
        //     }
        //     if(s.find(temp) == s.end())ans.push_back(temp);
        //     s.insert(temp);
        // }
        
        
        // return ans;
        
        // Space Optimization SC(R)
        vector<vector<int>>ans;
        unordered_map<long long,int>mp;
        for(int i=0;i<r;i++){
            long long int binaryToDecimal=0;
            vector<int>v;
            for(int j=0;j<c;j++){
                binaryToDecimal=2*binaryToDecimal+a[i][j];
                v.push_back(a[i][j]);
            }
            if(mp[binaryToDecimal]==0)ans.push_back(v);
            mp[binaryToDecimal]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends