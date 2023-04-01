//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	// Recursion : TC (2^N)
// 	    void generateString(string temp,vector<string>& ans,int ind,string s){
// 	        if( ind == s.length()){
// 	            if(temp == "")return;
// 	            ans.push_back(temp);
// 	            return;
// 	        }
	        
// 	        generateString(temp+s[ind],ans,ind+1,s);
// 	        generateString(temp,ans,ind+1,s);
	        
// 	    }
	
// 		vector<string> AllPossibleStrings(string s){
// 		    //Code here
// 		    if(s.length() == 1){
// 		        return {s};
// 		    }
// 		    vector<string> ans;
// 		    string temp = "";
// 		    generateString(temp,ans,0,s);
// 		    sort(ans.begin(),ans.end());
// 		    return ans;
// 		}

        // Bits Manipulation : TC(n*2^n)
        
        vector<string> AllPossibleStrings(string s){
           vector<string> ans;
           string temp;
           
           for(int i = 0; i <= pow(2,s.length())-1 ; i++){
               temp = "";
               for(int k=0 ; k < s.length(); k++){
                   if( i  &  (1<<k)){
                       temp += (s[k]);
                   }
               }
               ans.push_back(temp);
           }
           sort(ans.begin(),ans.end());
           ans.erase(ans.begin());
           return ans;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends