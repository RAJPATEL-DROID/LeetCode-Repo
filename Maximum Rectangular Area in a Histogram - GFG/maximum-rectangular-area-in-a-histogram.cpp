//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long h[], int n)
    {
        // Your code here
    //     vector<int> smlLeft(n),smlRight(n);
    //     stack<int> s;
        
    //     for(int i= 0; i < n; i++){
    //         while(!s.empty() && h[s.top()] >= h[i] ){
    //             s.pop();
    //         }
    //         if(s.empty())smlLeft[i] =0;
    //         else smlLeft[i] = s.top() + 1;
    //         s.push(i);
    //     }
        
    //     while(!s.empty())s.pop();
        
        
    //     for(int i= n-1;i >=0 ;i--){
    //         while(!s.empty() && h[s.top()] >= h[i]){
    //                 s.pop();
    //         }
    //         if(s.empty())smlRight[i] = n-1;
    //         else smlRight[i] = s.top() - 1;
    //         s.push(i);
    //     }
        
    //   long long ans =0;
    //     for(int i=0;i <n;i++){
    //         ans = max(ans, h[i]* (smlRight[i] - smlLeft[i]+1 ));
    //     }
    //     return ans;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends