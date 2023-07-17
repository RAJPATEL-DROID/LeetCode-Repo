//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> s(26,0);
		    queue<char> q;
		    string ans="";
		    for(int i=0; i< A.length(); i++){
		        if(s[A[i]-'a']  == 0){
		            s[A[i]-'a'] = 1;
		            q.push(A[i]);
		        }else {
		            s[A[i] - 'a']++;
		        }
		        while(true){
		            if(q.empty()){
		                ans += "#";
		                break;
		            }
		            if(s[q.front()-'a'] == 1){
		              //  cout<<q.front()<<" "<<s[q.front()-'a']<<" ";
		                ans += q.front();
		                break;
		            }else{
		                q.pop();
		            }
		        }
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends