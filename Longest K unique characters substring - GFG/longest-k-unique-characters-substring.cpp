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
        // My code
        // unordered_map<char,int> m;
        // int ans =0;
        // int i=0,j=0;
        // while(j < s.length()){

        //     // if curr char is not in the map so we need to remove one char type
        //     if(m.find(s[j]) == m.end() && m.size() == k){
        //         // Store the current length in ans 
        //         ans = max(ans,j-i);
                
        //         // until the map size is k remove char from front of window
        //         while(m.size() == k){
                    
        //             // removing the freq of char at front
        //             m[s[i]]--;
                    
        //             // if the freq of char at front became zero then the k will be reduced to k -1
        //             // now we can include our curr char in the window
        //             if(m[s[i]] == 0){
        //                 m.erase(s[i]);
        //                 m[s[j]]++;
        //                 i++;
        //                 // cout<<i<<"\n";
        //                 break;
        //             }
        //             i++;
        //         }
        //     }else{
        //         m[s[j]]++;
        //     }
        //     j++;
        // }
        
        // // cout << m.size()<<"\n";
        // if(m.size() != k)return -1;
        // ans = max(ans,j-i);
        // return ans;
    
        //     Leetcode Official Solution
        
        int cnt[128] = {}, distinct = 0, i = 0, j = 0, ans = 0, N = s.size();
        while (j < N) {
            distinct += cnt[s[j++]]++ == 0;
            while (distinct > k) distinct -= --cnt[s[i++]] == 0;
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