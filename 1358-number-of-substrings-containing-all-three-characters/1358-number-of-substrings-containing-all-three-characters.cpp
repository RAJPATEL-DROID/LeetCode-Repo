class Solution {
public:
    int numberOfSubstrings(string s) {
        int start =0,end=0,a=0,b=0,c=0,ans=0;
        int n = s.size();
        
        while(end < n){
            if(s[end] == 'a')a++;
            if(s[end] == 'b')b++;
            if(s[end] == 'c')c++;
            
            while( a> 0 && b>0 && c>0){
                ans += n - end;
                if(s[start] == 'a')a--;
                if(s[start] == 'b')b--;
                if(s[start] == 'c')c--;
                start++;
            }
            end++;
        }
        return ans;
    }
};