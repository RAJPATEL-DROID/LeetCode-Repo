//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        
        // Binary Search 
        
        // vector<int>v;
        // int maxi=INT_MIN;
        // for(int i = n-1 ; i >=0 ; i--){
        //     maxi=max(maxi,arr[i]);
        //     v.push_back(maxi);
        // }
        // maxi=INT_MIN;
        // for(int i = 0 ; i < n ; i++){
        //     int idx=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        //     idx=n-idx-1;
        //     maxi=max(maxi,idx-i);
        // }
        // return maxi;
        
        // Optimal Solution
        // Use 2 Arryas : Max Array and MinArray
        vector<int> maxArr(n);
        vector<int> minArr(n);
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=n-1; i >= 0; i--){
             maxi = max(maxi,arr[i]);   
             maxArr[i] = maxi;
        }
        
        for(int i=0;i<n;i++){
            mini = min(mini,arr[i]);
            minArr[i]  = mini;
        }
        
        int ans = INT_MIN;
        int i=0,j=0;
        while(i < n && j < n){
            if(minArr[i] <= maxArr[j]){
                ans = max(ans,j-i);
                j++;
            }else {
                i++;
            }
        }
        return ans;
        
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