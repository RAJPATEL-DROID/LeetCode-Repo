//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int j = 0;
        int cnt =0,celeb=-1;
        for(int i =0 ;i<n;i++){
            int flag =1;
            for(j=0; j < n; j++){
                if(i == j || (M[i][j] == 0 && M[j][i] == 1))continue;
                else {
                    flag =0;
                    break;
                    
                }
            }
            if(j == n && flag){
                celeb = i;
                cnt++;
            }
        }
        
        return cnt>1?-1:celeb;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends