//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int n, vector<int> &nums) {
        // code here
       
        long long answer = 0;
        stack<int> stk;
        
        // Find the sum of all the minimum.
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() && (right == n || nums[stk.top()] >= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer -= (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right); 
        }
        
        // Find the sum of all the maximum.
        stk.pop();
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() && (right == n || nums[stk.top()] <= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer += (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right); 
        }
        return answer;
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
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends