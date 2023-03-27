//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int n = N,i=0;
        while(n>0){
            if(n&1){
                n >>= 1;
                i++;
            }else{
                N = N | (1<<i);break;
            }
        }
        return N;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends