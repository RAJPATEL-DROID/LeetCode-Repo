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
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        /*int j = 0;
        int cnt =0,celeb=-1;
        for(int i =0 ;i<n;i++){
            int flag =1;
            for(j=0; j < n; j++){
                if(i == j || (m[i][j] == 0 && m[j][i] == 1))continue;
                else {
                    flag =0;
                    break;
                    
                }
            }
            if(j == n && flag){
                celeb = i;
                cnt++;
            }
            return cnt>1?-1:celeb;
        }*/
        
        // Stack approach
        // stack<int> s;
        // for(int i=0; i< n; i++){
        //     s.push(i);
        // }
        
        // Find the Viable Celebritry position
        // while(s.size() > 1){
        //     int i = s.top();s.pop();
        //     int j = s.top();s.pop();
            
        //     if(m[i][j] == 1){
        //         s.push(j);
        //     }
        //     else s.push(i);
        // }
        
        // int celeb = s.top();s.pop();
        
        // Check if the postion we got have celebrity  or not
        // for(int i=0; i < n; i++){
        //     if(i != celeb){
        //         if(m[i][celeb] == 0 || m[celeb][i] == 1){
        //             return -1;
        //         }
        //     } 
        // }
        // return celeb;
        
        // Two Pointer Approach
        // Here we are considering the 2D array into 1D 
        int start =0,end =n-1;
        
        
        while(start<end){
            if(m[start][end] == 1)start++;
            else end--;
        }
        
        for(int i=0; i < n; i++){
            if(i != start)
            {
                if(m[i][start] == 0 || m[start][i] == 1)return -1;
            }
        }
        return start;
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