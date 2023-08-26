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
        // int cnt[26] = {};
        // int distinct = 0;
        // int i = 0, j = 0;
        // int ans = 0;
        // int N = s.size();
        
        // while (j < N) {
        //     if(cnt[s[j++]-'a']++ == 0){
        //         distinct += 1;
        //     }
        //     while (distinct > k) distinct -= --cnt[s[i++]-'a'] == 0;
        //     ans = max(ans, j - i);
        // }
        // if(distinct == k)return ans;
        // return -1;
        unordered_map<char,int> m;
        int i=0;
        int j=0;
        int ans=-1;
        
        while(j < s.length()){
            m[s[j]]++;
            
            if(m.size()> k){
                m[s[i]]--;
                if(m[s[i]] == 0){
                    m.erase(s[i]);
                }
                i++;
            }
            
            if(m.size() == k)ans = max(ans,j-i + 1);
            
            j++;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends