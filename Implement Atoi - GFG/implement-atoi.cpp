//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int f(string &str,int sign,int i,int result){
        if(i >= str.size()){
            return sign*result;
        }
        
        if(str[i] < '0' or str[i] > '9')return -1;
        
        int temp = str[i] - '0';
        return f(str,sign,i+1,result*10 + temp);
    }
    
    int atoi(string str) {
        int i =0,sign = 1;
        if(str[0] == '-')sign=-1,++i;
        
        f(str,sign,i,0);
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