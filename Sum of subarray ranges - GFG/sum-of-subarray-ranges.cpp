//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int n, vector<int> &nums) {
        // code here
       
        long long ans =0,mid,left,boundary;
        stack<int> s;
        
        for(int right =0; right <= n; right++){
            
            while( !s.empty() && nums[s.top()] > (right == n ? -2e9 : nums[right]) ){
                mid = s.top(); s.pop();
                
                left =s.empty() ? -1 : s.top();
                
                boundary = (mid - left)* (right - mid);
                
                ans -= (boundary) * nums[mid];
            }
            s.push(right);
        }
        
        s = stack<int>();
        
        // Now Find No. of times element occurs as Maximum in subarrays'
        for(int right=0 ; right <= n; right++){
            
            while(!s.empty() && nums[s.top()] < (right==n?2e9 : nums[right]) ){
                
                mid = s.top(); s.pop();
                
                left = s.empty()? -1 : s.top();
                
                boundary = (mid - left) * (right - mid);
                
                ans += (boundary) * nums[mid];
            }
            s.push(right);
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
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends