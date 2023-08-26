//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int cnt[26] = {}, distinct = 0, i = 0, j = 0, ans = 0, N = s.size();
        while (j < N) {
            distinct += cnt[s[j++]-'a']++ == 0;
            while (distinct > k) distinct -= --cnt[s[i++]-'a'] == 0;
            ans = max(ans, j - i);
        }
        if(distinct == k)return ans;
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends