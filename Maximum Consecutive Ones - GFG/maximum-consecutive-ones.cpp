//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int len = 0;
        int i =0, j =0,currZeroes =0;
        while( j < n ){
            if(nums[j] != 0){
                // cout<<"end"<<j <<"start" <<i<<"\n";
                len = max(len,j-i+1);
            }else{
                if(currZeroes < k){
                    currZeroes++;
                }else if(currZeroes == k){
                    while(nums[i] != 0){
                        i++;
                    }
                    i++;
                }
                // cout<<"end"<<j <<"start" <<i<<"\n";
                len = max(len,j-i+1);
            }
            j++;
        }
        // cout<<currZeroes<<"\n";
        // cout<<"end"<<j <<"start" <<i<<"\n";
        len = max(len,j-i);
        return len;
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
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends