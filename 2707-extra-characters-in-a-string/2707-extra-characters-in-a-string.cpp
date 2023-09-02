class Solution {
public:
    int dp(int start,string s,unordered_set<string>& dict,unordered_map<int,int>& memo,int n){
        if(start == n)return 0;
        
        if(memo.count(start)){
            return memo[start];
        }
        
        int ans = dp(start + 1,s,dict,memo,n) + 1;
        
        for(int end = start; end < n; end++){
            auto curr = s.substr(start,end- start + 1);
            if(dict.count(curr)){
                ans = min(ans,dp(end + 1,s,dict,memo,n));
            }
        }
        
        return memo[start] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        unordered_map<int,int> memo;
        
        return dp(0,s,dict,memo,n);       
    }
};