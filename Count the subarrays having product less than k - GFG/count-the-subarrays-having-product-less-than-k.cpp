//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // int ans=0;
        // for(int i=0;i<n;i++) {
        //     long long mul=1;
        //     for(int j=i;j<n;j++) {
        //         mul = mul * a[j];
        //         if(mul < k) {
        //             ans++;
        //         } else {
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        if (k <= 1) return 0;
        
        int count = 0;
        int left = 0;
        int right = 0;
        long product = 1;
        
        while (right < n) {
            product *= a[right];
            
            while (product >= k) {
                product /= a[left];
                left++;
            }
            
            count += right - left + 1;
            right++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends