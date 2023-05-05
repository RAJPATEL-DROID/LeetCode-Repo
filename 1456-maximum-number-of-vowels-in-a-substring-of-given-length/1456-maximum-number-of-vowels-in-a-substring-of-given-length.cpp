class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int cnt = 0;
        int ans =0;
        
        for(; j < k; j++){
            if(isVowel(s[j])){
                cnt++;
                // cout<<s[j]<<" "<<cnt<<"\n";
            }
        }
        ans += max(cnt,ans);
        // cout<<ans<<"\n";
         
        while(j < s.length()){
            if(isVowel(s[i]))cnt--;
            i++;
            if(isVowel(s[j]))cnt++;
            // cout<<s[j]<<" "<<cnt<<"\n";
            ans =max(ans,cnt);
            j++;
        }
        return ans;
    }
};