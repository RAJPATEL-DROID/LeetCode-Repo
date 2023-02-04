//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans = 0;
        int flag =0;
        if(str[0] == '-')flag=1;
        for(int i=0;i<str.length();i++){
            if((str[i] < '0' || str[i] >'9')){
                if(i==0 && str[i] == '-')continue;
                return -1;
            }
        }
        int j=str.length()-1;
        int i=1;
        while(j>=0){
            ans += (str[j]-'0') * i;
            // cout << ans<< " ";
            i *= 10;
            j--;
            if(str[j] == '-')break;
        }
        
        if(flag == 1)return -1*ans;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends