class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen =0,len =0,start =0;
        int n =  s.length();
        
        for(int i =0 ;i < n; i++){
            int l =i-1, r = i+1;
            
            while(l>=0 && s[i] == s[l])l--;
            while(r < n && s[i] == s[r])r++;
            
            while(l>=0 && r < n && s[l] == s[r]){
                l--;r++;
            }
            
            len = r-l-1;
            
            if(len > maxLen){
                start = l+1;
                maxLen = len;
            }
        }
        return s.substr(start,maxLen);
    }
};