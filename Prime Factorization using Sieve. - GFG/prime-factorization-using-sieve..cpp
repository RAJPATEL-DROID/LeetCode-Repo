//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int n = 100100;
vector<int> Sieve(n+1);
class Solution {
  public:
  
    void sieve() {
        for(int i =1;i<= n; i++){
                Sieve[i] = i;
            
        }            
        
        for(int i=2; i*i <= n; i++){
            if(Sieve[i] == i){
                for(int j = i*i; j <= n; j += i){
                    if(Sieve[j] == j ){
                        Sieve[j] = i;
                    }
                }
            }
        }
        
    };

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        sieve();
        vector<int> ans;
        
        while(N != 1){
            ans.push_back(Sieve[N]);
            N /= Sieve[N];
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends