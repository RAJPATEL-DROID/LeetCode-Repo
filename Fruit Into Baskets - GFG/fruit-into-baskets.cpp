//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
         // Hash map 'basket' to store the types of fruits.
        unordered_map<int, int> basket;
        int left, right,cnt=0;
        
        // Add fruit from the right index (right) of the window.
        for (left = 0, right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            
            // If the current window has more than 2 types of fruit,
            // we remove one fruit from the left index (left) of the window.
           while(basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            
            cnt = max(cnt,right-left+1);
        }
        
        // Once we finish the iteration, the indexes left and right 
        // stands for the longest valid subarray we encountered.
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends