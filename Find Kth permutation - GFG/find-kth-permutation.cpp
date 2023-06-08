//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> v(n, 0);
        for(int i=0;i<n;i++)    v[i] = i+1;
        k--;
        vector<int> kthP(n, 0);
        vector<int> fact(n, 1);
        
        // Calculating Factorials
        for(int i=2;i<n;i++){
            int f = fact[i];
            fact[i] = fact[i-1] * i;
        }
        
        
        // What happen is you want to find kth permutation number
        // so if you select one number at first position ,then for that number to be
        // at first position,you will get (n-1)! different numbers
        //  n = 4, k = 9
        // suppose at 1st pos ,we put 4
        // so, 4xyz
        // so in xyz we can put 1,2,3 in total 3! = 6 ways
        // 4 1 2 3
        // 4 1 3 2
        // 4 2 1 3
        // 4 2 3 1
        // 4 3 1 2 
        // 4 3 2 1
        
        // so Initially when we do k/(n-1)! => we get the index of number which will be in our first position
        // so we remove that number from our original n numbers and reduce the k to k%(n-1);
        // Again repeat the cycle untill our k becomes 0;
        int i = 0;
        while(k > 0){
            int f = fact[v.size()-1];
            int ind = k/f;
            kthP[i] = v[ind];
            k %= f;
            v.erase(v.begin() + ind);
            // for(auto x :v)cout<<x<<" ";
            i++;
            // cout<<k<<"\n";
        }
        
        
        // if the all n numbers are not 
        int j = 0;
        while(i<n){
            kthP[i] = v[j];
            i++, j++;
        }
        
        string ans = "";
        for(int i=0;i<n;i++){
            ans += to_string(kthP[i]);
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
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends