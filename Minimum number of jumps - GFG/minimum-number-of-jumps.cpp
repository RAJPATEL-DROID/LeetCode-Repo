//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        if(arr[0] == 0)return -1;
        if(n <=1){
            return 0;
        }
        
        int ladder = 0;
        int stairs = 0;
        int jump =0;
        
        for(int level=0 ;level < n-1; level++){
            
            if(level + arr[level] > ladder){
                ladder = level + arr[level];
            } 
            
            if(level == stairs){
                jump++;
                stairs = ladder;
            }
            
            if(arr[level] == 0 && level == ladder){
                return -1;
            }
        }
        
        return jump;
        
        
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends