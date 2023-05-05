//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &c, int N, int k) {
        // code here
        // int N = c.size();
        int i=0,j=0;
        int total_Sum =0;
        for(int i=0;i < N;i++){
            total_Sum += c[i];
        }
        if(N == k)return total_Sum;
        i=0;
        int win_sum =0;
        while(j != (N-k)){
                  win_sum += c[j++];  
        }
        int ans = total_Sum - win_sum;
        for(int j= (N-k); j < N; j++){
            win_sum -= c[i++];
            win_sum += c[j];
            ans = max(ans,total_Sum - win_sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends