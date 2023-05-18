//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        // Store the freequency of characters of string p
        unordered_map<char,int> m;    
        for(int i = 0; i < p.length(); i++){
            m[p[i]]++;
        }
        // get the starting point of min substring
        int start =0;
        int i=0,j=0,count = m.size();
        int minLen =INT_MAX;
        
        while(j < s.length()){
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0)count--;
            }
            if(count ==0)
            {
                while(count == 0){
                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;
                        if(m[s[i]] == 1){
                            count++;
                            if(j - i + 1 < minLen){
                                minLen = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(minLen == INT_MAX)return "-1";
        return s.substr(start,minLen);
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends