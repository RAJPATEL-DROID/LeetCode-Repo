//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int g= (num & (1 << (i-1)));  
        
        if(g){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
        
        int s = (num | (1 << (i-1)));
        cout<< s <<" ";
        
        int c = (num & (~(1<<(i-1))));
        cout<< c << " ";
        
        return;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends