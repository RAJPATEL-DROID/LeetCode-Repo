//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int>v;
        int maxi=INT_MIN;
        for(int i = n-1 ; i >=0 ; i--){
            maxi=max(maxi,arr[i]);
            v.push_back(maxi);
        }
        maxi=INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int idx=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
            idx=n-idx-1;
            maxi=max(maxi,idx-i);
        }
        return maxi;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends