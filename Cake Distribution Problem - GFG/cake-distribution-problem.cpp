//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool canProvide(vector<int>& s,int m,int k){
        int cnt =0,sum=0;
        
        for(int i=0;i < s.size();i++){
            sum += s[i];
            if(sum >= m){
                cnt++;
                sum=0;
            }
        }
        
        return cnt>=k+1?true:false;
        
    };
    
    int maxSweetness(vector<int>& sweetness, int n, int k) {
    // Write your code here.
        int l =INT_MAX,h =0;
        for(int i : sweetness){
            l =min(l,i);
            h += i;
        }
        int ans=0;
        while(l <= h){
            int mid = (l + h)>>1;
            if(canProvide(sweetness,mid,k)){
                ans =mid;
                l = mid +1;
            }else{
                h = mid-1;
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
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends