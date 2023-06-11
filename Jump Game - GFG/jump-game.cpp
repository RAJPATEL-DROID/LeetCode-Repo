//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        //strat iterating from last index till the 0th index
        //if I'm able to reach at 0th index, then return true
        //else, return false
    
        int target = N-1;
        for(int i=N-1; i>=0; i--)
        {
            //If from ith index it's possible to reach the last index,
           // then new target is the ith index, 
          //  as if we are successful in finding path till ith index then I can goto the last index..
            if(i + A[i] >= target)
            {
                target = i;
            }
        }
    
    
        //If we are able to reach in 0th index, then return true
        //else, return false
    
        return (target==0);
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends