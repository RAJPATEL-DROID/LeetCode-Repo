//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> c, vector<int> r) {
         // Traverse from 1 to N-1 index of array
         // check if curr index elements in both array have same value as previous index ele or not
         // if same values in both arrays,then remove previous ele from stack
         // else store the curr index in the stack
         stack<int> st;
         for(int i=0; i< N; i++){
             if(!st.empty() &&  c[i] == c[st.top()] && r[i] == r[st.top()] ){
                 st.pop();
             }else{
                 st.push(i);
            }
        }
        int cnt =0;
        while(!st.empty()){
             st.pop();
             cnt++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends