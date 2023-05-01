//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector< int> m(256,-1);
        int i =0,j=0;
        int n = s.length();
        int len =0;
        while(j < n){
            if(m[s[j]] != -1){
                i = max(m[s[j]] +1 , i);
            }
            
            m[s[j]] = j;
            len = max(len, j - i +1);
            j++;
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends