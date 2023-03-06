//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	bool checkPalindrome(string& s,int i){
	    if( i >= s.length()/2 ) {
	        return true;
	    }
	    if(s[i] != s[s.length()-1-i]){
	        return false;
	    }
	    return checkPalindrome(s,i+1);
	}
	int isPalindrome(string S)
	{
	    // Your code goes here
	    return checkPalindrome(S,0);
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
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends