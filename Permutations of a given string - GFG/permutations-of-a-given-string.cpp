//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void util(string s,int l,int r,set<string>& v){
	    if(l==r){
	        v.insert(s);
	    }
	    
	    for(int i=l;i<=r;i++){
	     swap(s[l],s[i]);
	     util(s,l+1,r,v);
	    swap(s[l],s[i]);
	        
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> v;
		    util(S,0,S.size()-1,v);
		    vector<string> ans(v.begin(),v.end());
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends