//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int n){
        // code here 
        if(s == 1 || n == 1 || 9*n <= s)return "-1";
        string ans="";
        
        for(int i =0;i<n-1;i++){
            if(s > 9){
                ans += '9';
                s -= 9;
            }else{
                ans += (s-1+'0');   //here by doing +'0' it will convert the s-1 into char from integer datatype
                s = 1;
            }
        }
        ans += (s+'0');
        
        for(int i=1 ;i < n;i++){
            if(ans[i] != '9'){
                //  cout<<ans[i]<<" ";
                ans[i]++;
                // cout<<ans[i-1]<<" ";
                ans[i-1]--;
                reverse(ans.begin(),ans.end());
                return ans;
            }
        }
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends