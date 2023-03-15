//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void GenerateSum(int i,int k,int n,vector<vector<int>>& ans,vector<int>& sum){
        if(i > 9){
                if(sum.size() == k){
                    int s =0;
                    for(int a:sum){
                        s += a;
                    }
                    if(s == n)ans.push_back(sum);
            }
            return;
        }
        if(sum.size()== k){
            int s =0;
            for(int a:sum){
                s += a;
            }
            if(s == n)ans.push_back(sum);
            return;
        }
        
        GenerateSum(i+1,k,n,ans,sum);
         
        sum.push_back(i);
        GenerateSum(i+1,k,n,ans,sum);
        sum.pop_back();
    }
    
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>> ans;
        vector<int> sum;
        GenerateSum(1,K,N,ans,sum);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends