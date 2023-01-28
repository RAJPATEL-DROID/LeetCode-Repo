//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool isvalid(vector<int> &stations, int n, int k, double mid)
    {
        int count = 0;
        double dis = 0;
        for(int i=1; i<n; i++){
            int temp = stations[i] - stations[i-1];
            dis = (double)temp/mid; // we are checking that how many stations can be put between adjacent station
            count += (int(dis));  
        }
        if(count <= k)   
            return true;
        return false;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){
      // Code here
        int n = stations.size();
        double lo =0;
        double hi = stations[n-1] - stations[0];
        double ans =0;
        while(hi - lo > 1e-6){
            double mid = (lo + hi )/2.0;
            if(isvalid(stations,n,K,mid) ){
                // we decrease distance between new possible stations -> hi = mid
                ans = mid;
                hi = mid;
            }
            else lo= mid;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends