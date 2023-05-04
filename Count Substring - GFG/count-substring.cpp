//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        
        // vector<int> cnt(3,-1);
        // int ans=0;
        // for(int i=0; i < s.length(); i++){
        //     cnt[s[i] - 'a']++;
        //     ans += min(cnt[0],min(cnt[1],cnt[2])) + 1;
        // }
        // return ans++;
        
        int start =0,end=0,a=0,b=0,c=0,ans=0;
        int n = s.size();
        
        while(end < n){
            if(s[end] == 'a')a++;
            if(s[end] == 'b')b++;
            if(s[end] == 'c')c++;
            
            while( a> 0 && b>0 && c>0){
                ans += n - end;
                if(s[start] == 'a')a--;
                if(s[start] == 'b')b--;
                if(s[start] == 'c')c--;
                start++;
            }
            end++;
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
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends