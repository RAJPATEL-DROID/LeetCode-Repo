//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int reml = (l-1)%4;
        int remr = r%4;
        int xorl=0,xorr=0;
        if(reml == 1)xorl = 1;
        if(reml == 2)xorl = l;
        if(reml == 3)xorl = 0;
        if(reml == 0)xorl = l-1;
        if(remr == 1)xorr = 1;
        if(remr == 2)xorr = r+1;
        if(remr == 3)xorr = 0;
        if(remr == 0)xorr = r;
        // cout<<xorr<<" "<<xorl<<"\n";
        return xorr^xorl;

    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends