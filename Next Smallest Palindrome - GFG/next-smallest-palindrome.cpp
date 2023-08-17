//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool isAllnine(int num[],int n){
        for(int i=0;i<n;i++)if(num[i] != 9)return false;
        return true;
    }
    
    int isLess(int num[],int n){
        int i= (n-1)/2, j = n/2;
        
        while(i >= 0 ){
            if(num[i] < num[j])return 1;
            else if(num[i] > num[j] )return 0;
            --i;++j;
        }
        return 1;
        
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	   if(isAllnine(num,n)){
	       vector<int> ans(n+1,0);
	       ans[0] = ans[n] = 1;
	       
	       return ans;
	   }
	   
	   vector<int> ans(num,num+n);
	   
	   int i= (n-1)/2,j = n/2;
	   int carry = isLess(num,n);
	   
	   while( i >= 0){
	       if(carry){
	           if(ans[i] == 9)ans[i] =0;
	           else ans[i]++,carry=0;
	       }
	       ans[j++] = ans[i--];
	   }
	   return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends