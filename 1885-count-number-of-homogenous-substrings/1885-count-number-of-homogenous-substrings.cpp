class Solution {
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s) {
        int ans =0;
        int i=0,j=0;
        int n = s.length();
        while( i < n){
            long long temp =1;
            int j= i+ 1;
            while(j < n && s[i] == s[j]){
                j++;
                temp++;
            }
            ans += (((temp+1)*temp)/2)%mod;
            i = j;
        }

        return (int) ans;
    }
};