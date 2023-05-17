//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int atmost(vector<int> &arr, int N, int k){
      vector<int> m(N+1,0);
        int cnt = 0, i = 0, j = 0, ans = 0;
        while (j < N) {
            if(m[arr[j]] == 0)cnt++;
            m[arr[j]]++;
            
            while(cnt > k){
                m[arr[i]]--;
                if(m[arr[i]]== 0)cnt--;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    };
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        int first = atmost(arr,N,k);
        int second = atmost(arr,N,k-1);
        return first - second;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends