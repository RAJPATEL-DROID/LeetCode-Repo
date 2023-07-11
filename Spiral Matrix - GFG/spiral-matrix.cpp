//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int up=0, down=n-1, left=0, right=m-1;
        //direction=0: left to right
        //direction=1: top to bottom
        //direction=2: right to left
        //direction=3: bottom to top
        
        while(up<=down && left<=right){
            
            // Traversing from L to R
            for(int i=left;i<= right;i++){
                k--;
                if(k==0)return a[up][i];
            }
            up++;
            
            
            // Traversing from Up to Down from Rightmost Column
            for(int i=up; i <= down; i++){
                k--;
                if(k==0)return a[i][right];
            }
            right--;
            
            
            
            if(down>= up){
                
                // Traversing Right to Left Side in Row
                for(int i=right;i>= left;i--){
                    k--;
                    if(k==0)return a[down][i];
                }
                down--;
            }
            
            
            if(left<= right){
                // Traversing from Lower Element to Upper Element in Column
                for(int i=down;i>=up;i--){
                    k--;
                    if(k==0)return a[i][left];
                }
                left++;
            }
        }
        return -1;
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
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends