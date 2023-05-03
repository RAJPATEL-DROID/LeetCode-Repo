//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& arr, int target) {
        // Code here
         int i =0, j =0;
        int cnt =0,ans =0;
        
        while( j < n){
            if(cnt < target){
                if(arr[j]%2 == 1){
                   cnt++; 
                }
                if(cnt == target)ans++;
                j++;
            }else{
                if(arr[j]%2 == 1){
                    while(arr[i]%2 == 0 && i < j){
                        i++;
                        ans++;
                    }
                    cnt--;i++;
                    cnt++;ans++;j++;
                }else{
                    int temp  =i;
                    while(arr[temp]%2 != 1){
                        temp++;ans++;
                    }
                    j++;
                    ans++;
                }
            }
        }
        
        while(i < j && arr[i]%2 != 1){
            if(cnt == target)ans++;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends