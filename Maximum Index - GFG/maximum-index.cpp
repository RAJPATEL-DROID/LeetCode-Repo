//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int v[], int n) 
    { 
        // Your code here
    vector<int> maxFromEnd(n + 1, INT_MIN);
 
    // create an array maxfromEnd
    for (int i = n - 1; i >= 0; i--) {
        maxFromEnd[i] = max(maxFromEnd[i + 1], v[i]);
    }
 
    int result = 0;
 
    for (int i = 0; i < n; i++) {
        int low = i + 1, high = n- 1, ans = i;
 
        while (low <= high) {
            int mid = (low + high) / 2;
 
            if (v[i] <= maxFromEnd[mid]) {
               
                // We store this as current answer and look
                // for further larger number to the right
                // side
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        // keeping a track of the
        // maximum difference in indices
        result = max(result, ans - i);
    }
    return result;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends