//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void generateNo(int n,vector<string>&  ans,string temp,int zero,int one){
        if(zero + one == n){
            ans.push_back(temp);
            return;
        }
        if(one >zero){
            generateNo(n,ans,temp+'1',zero,one+1);
            generateNo(n,ans,temp+'0',zero+1,one);
        }else{
            generateNo(n,ans,temp+'1',zero,one+1);
        }
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> ans;
	    int one=0,zero=0;
	    generateNo(N,ans,"",zero,one);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends