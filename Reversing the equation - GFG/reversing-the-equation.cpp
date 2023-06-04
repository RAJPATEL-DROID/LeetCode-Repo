//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans ="";
            string num ="";
            for(int i=0; i < s.length(); i++){
                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
                    ans = num + ans;
                    ans = s[i] + ans;
                    // cout<<ans<<"\n";
                    num = "";
                    continue;
                }
                num += s[i];
            }
            ans = num + ans;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends