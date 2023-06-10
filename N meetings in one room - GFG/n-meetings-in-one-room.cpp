//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int> > m;
        for(int i=0; i < n;i++){
            m.push_back({end[i],start[i]});
        }
        
        sort(m.begin(),m.end());
        
        int cnt =1;
        int lastmeet= m[0].first; // store last meetings finish time
        for(int i=1;i <n; i++){
            
            // compare lastmeet with the next meetings start time
            if(lastmeet < m[i].second){
                cnt++;
                lastmeet = m[i].first;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends