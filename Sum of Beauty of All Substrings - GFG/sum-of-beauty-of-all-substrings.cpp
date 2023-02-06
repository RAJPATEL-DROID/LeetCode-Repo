//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans =0;
        
        for(int i=0;i<s.length(); i++){
            vector<int> freq(26,0);
            for(int j =i; j< s.length();j++){
                freq[s[j]-'a']++;
                int mn = INT_MAX;
                int mx = INT_MIN;
                for(int k =0;k<26;k++){
                    if(freq[k]==0)continue;
                    mn =min(mn,freq[k]);
                    mx =max(mx,freq[k]);
                }
                ans += (mx-mn);
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
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends