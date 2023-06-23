//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        //calculate frequency of each element
        unordered_map<int,int> freqMap;
        int maxFreq = 0; //maximum of all elements frequency
        for(int i = 0; i < N; i++)
        {
            freqMap[tasks[i]]++;
            maxFreq = max(maxFreq, freqMap[tasks[i]]);
        }
        //for maxFreq - 1 elements it will take Cooldown period + 1(to execute) time each
        int ans = (maxFreq - 1) * (K + 1);
        //Now adding the ones for executing equal to maxFreq
        for(auto element : freqMap)
        {
            if(element.second == maxFreq) ans++; //adding one for executing that task
        }
        
        //edge case where ans won't work ["A","A","A","B","B","B"]  k = 0
        // we need minimum tasks.size() time, since we take 1 unit time for each task
        return max((int)tasks.size(), ans);
 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends