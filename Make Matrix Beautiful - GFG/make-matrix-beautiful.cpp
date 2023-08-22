//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int row_sum[n]={0},col_sum[n]={0};
        
        for(int i=0;i< n;i++){
            for(int j=0;j< n; j++){
                row_sum[i] += matrix[i][j];
                col_sum[j] += matrix[i][j];
            }
        }
        
        int max_sum =0;
        
        for(int i=0;i<n;i++){
            max_sum = max(max_sum,max(row_sum[i],col_sum[i]));
        }
        
        for(int i=0;i < n; i++){
            row_sum[i] = max_sum - row_sum[i];
            col_sum[i] = max_sum - col_sum[i];
        }
        
        int ans =0;
        for(int i=0;i < n;i++){
            for(int j=0;j < n; j++){
                int min_ops = min(row_sum[i],col_sum[j]);
                ans += min_ops;
                row_sum[i] -= min_ops;
                col_sum[j] -= min_ops;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends