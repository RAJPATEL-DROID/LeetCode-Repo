//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        int i =0,j=0,ans=0;
        // unordered_map<char,int> m;
        int hashmap[26]={0};
        int cnt=0;
        for(;j < s.length(); j++){
            hashmap[s[j]-'A']++;
            
            cnt = max(cnt,hashmap[s[j]-'A']);
            
            while( (j- i+1) - cnt > k){
                hashmap[s[i]-'A']--;
                i++;
            }
            
            ans = max(ans,j-i+1);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends