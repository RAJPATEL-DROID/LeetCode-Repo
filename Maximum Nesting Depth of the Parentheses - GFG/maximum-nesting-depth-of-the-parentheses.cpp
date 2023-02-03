//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        if(s.length()==0)return 0;
        int tempDepth = 0;
        int ans = 0;
        for(int i=0; i < s.length(); i++){
            if(s[i] == '('){
                tempDepth++;
            }else if(s[i] == ')' ){
                ans =max(ans,tempDepth);
                tempDepth--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends