class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long len = 0;
        for(char c : s){
            if(isdigit(c)){
                len *= (c - '0');
            }else{
                len++;
            }
        }

        for(int i=s.length() - 1; i >=0 ;i--){
            k = k % len;
            if(k ==0 && !isdigit(s[i])){
                return string(1,s[i]);  // returns string of 1 copy of char at index i
            }
            if(isdigit(s[i]) ){
                len /= (s[i]-'0');
            }else{
                len--;
            }
        }

        return string(1,'str');
    }
};