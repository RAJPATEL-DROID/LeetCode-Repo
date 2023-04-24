//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int K) {
        if(s.length() <= K)return "0";
        
        if(K ==0)return s;      
        
        stack<char> st;
        
        for(int i = 0; i< s.length(); i++){
        
            while(!st.empty() && K>0 &&  (s[i]) < st.top()){
                st.pop();
                K--;
            }
        
            if(st.size() || s[i] != '0')st.push(s[i]);
        }
        
        while(K && !st.empty()){
            K--;
            st.pop();
        }
        
        if(st.empty())return "0";
        string ans= "";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
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
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends