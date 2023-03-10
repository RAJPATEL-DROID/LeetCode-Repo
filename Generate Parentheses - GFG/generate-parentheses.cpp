//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generateString(string s,vector<string>& ans,int i ,int j,int n){
        // base case
        if(i >= n && i == j){
            if(j != n){
                generateString(s,ans,i,j+1,n);
                return;
            }else{
                ans.push_back(s);
                return;
            }
        }
        
        // we add ( 
        if(i < n){
        generateString(s+'(',ans,i+1,j,n);
        }
        
        
        // we add ) if and only j < i and j < n
        if(i > j){
            generateString(s+')',ans,i,j+1,n);
        }
    };
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string s="";
        int i=0,j =0;
        generateString(s,ans,i,j,n);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends