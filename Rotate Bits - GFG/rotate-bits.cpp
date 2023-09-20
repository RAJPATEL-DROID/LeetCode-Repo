//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            int a,b;
            d = d%16;
            int leftr = n <<d;
            int leftAdd = n >>(16-d);
            a = (leftr | leftAdd) & 65535;
            int rightr = n >> d;
            int rightAdd = n <<(16-d);
            b = (rightr | rightAdd ) & 65535;
            return {a,b};
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends