//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    long long int countDistinct(string s,int k){
        int i=0;
        int j= 0;
        int dist_chr = 0;
        int n = s.length();
        int char_cnt[26] ={0};
        long long int ans =0;
        while(j < n){
            char_cnt[s[j]-97]++;
            
            if(char_cnt[s[j]-97] == 1) dist_chr++;
            
            while(dist_chr > k){
                char_cnt[s[i]-97]--;
                
                if(char_cnt[s[i] - 97] == 0){
                    dist_chr--;
                }
                i++;
            }
            
            ans += j+1-i;
            j++;
        }
        
        return ans;
    }
    
    
    long long int substrCount (string s, int k) {
    	long long int ans = countDistinct(s,k) - countDistinct(s,k-1);
    	return ans;
    	  
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends