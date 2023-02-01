//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        int j=0,flag=1,len=0;
        while( j < arr[0].length() ) {
            char c = arr[0][j];
            for(int i=1;i<N;i++){
                if(arr[i][j]!=c)
                {
                    flag =0;
                }
            }    
            if(flag){
                len++;
                j++;
            }else{
                break;
            }
        }
        if(j==0 && len ==0){
            return "-1";
        }else if(j==0){
            return arr[0].substr(0,0);
        }else{
            return arr[0].substr(0,j);
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends