//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& a) {
        // code here
        vector<int> ans(N,-1);
        stack<int> s;
        
        for(int i=2*N -1;i >= 0;i--){
            if(s.empty()){
                ans[i%N] = -1;
            }else if(s.size() > 0 && a[i%N] < s.top()){
                ans[i%N] = s.top();
            }else if(s.size() > 0 && a[i%N] >= s.top()){
                while(s.size() > 0 && s.top() <=a[i%N] ){
                    s.pop();
                }
                if(s.size() > 0){
                    ans[i%N] = s.top();
                }else{
                    ans[i%N] = -1;
                }
            }
            s.push(a[i%N]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends