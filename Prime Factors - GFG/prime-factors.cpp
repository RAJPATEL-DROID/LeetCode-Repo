//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	bool isprime(int n){
	    int cnt =0;
	    
	    for(int i=1; i*i <= n; i++){
	        if(n%i == 0){
	            cnt++;
	            if(n/i != i){
	                cnt++;
	            }
	        }
	    }
	    if(cnt ==2)return true;
	    return false;
	}
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    if(isprime(N)){
	        return {N};
	    }
	    vector<int> ans;
	    for(int i=2;i <= N; i++){
	        if((N%i) == 0 && isprime(i)){
	            ans.push_back(i);
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
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends