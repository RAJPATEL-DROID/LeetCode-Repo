class Solution {
public:
    string longestPalindrome(string s) {
        // int maxLen =0,len =0,start =0;
        // int n =  s.length();
        
        // for(int i =0 ;i < n; i++){
        //     int l =i-1, r = i+1;
            
        //     while(l>=0 && s[i] == s[l])l--;
        //     while(r < n && s[i] == s[r])r++;
            
        //     while(l>=0 && r < n && s[l] == s[r]){
        //         l--;r++;
        //     }
            
        //     len = r-l-1;
            
        //     if(len > maxLen){
        //         start = l+1;
        //         maxLen = len;
        //     }
        // }
        // return s.substr(start,maxLen);

        int n = s.size();
        int start = 0,maxLen =0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int len =0; len < n;len++){
            for(int i=0, j = len; j < n; j++,i++){
                if(isPalindrome(dp,s,i,j) && len >= maxLen){
                    start = i;
                    maxLen = len + 1;
                }
            }
        }
        return s.substr(start,maxLen);
    }

    bool isPalindrome(vector<vector<bool>>& dp,string& s,int i,int j){
        if(i == j){
            return dp[i][j] = true;
        }else if(j - i == 1){
            return dp[i][j] = s[i]==s[j];
        }else{
            return dp[i][j] = dp[i+1][j-1] ? s[i]==s[j]:false;
        }
    }
};