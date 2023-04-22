//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int N, vector<int> &arr) {
        // code here
        int mod = 1e9+7;
        stack<int> s;
        long long ans =0;
        // We will be implementing Monotonically increasing stack
        for(int i=0 ;i <= N;i++){
            
            while(!s.empty() && (i == N || arr[s.top()] >= arr[i] )){
                int curr_ele = s.top();
                s.pop();
                
                //so for curr_element, element which is now on top is the previously smaller element,
                // leftBoundary is index of prev smaller ele
                int leftBoundary = s.empty()? -1 : s.top();
                
                // for curr_element, element at i is the next smaller element,as arr[i] < curr_element
                int rightBoundary = i;
                
                int totalSubarray = (rightBoundary - curr_ele)*(curr_ele - leftBoundary) % mod;
                
                ans += (arr[curr_ele]* totalSubarray);
                ans %= mod;
            }
            s.push(i);
        }
        return (int)ans;
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
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends