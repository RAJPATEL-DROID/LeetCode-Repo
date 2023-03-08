//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isGood(int n,int D,int sum){
        if(n == 0){
            return true;
        }
        int num = n % 10;
        // cout<<"n "<<n<<"num  "<< num <<" \n"; 
        if(num == D)return false;
        if(sum >=  num){
            return false;
        }else{
            sum += num;
            // cout<<sum<<" \n";
            n = n/10;
            return isGood(n,D,sum);
        }
    }
    
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int> ans;
        for(int i=L;i<=R;i++){
            if(i%10 == D)continue;
            if(isGood(i/10,D,i%10)){
                ans.push_back(i);
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
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends