class Solution {
public:
    int maxDepth(string s) {
        if(s.length()==0)return 0;
     int tempDepth = 0;
        int ans = 0;
        for(int i=0;i < s.length(); i++){
            if(s[i] == '('){
                tempDepth++;
            }else if(s[i]== ')'){
                ans = max(ans,tempDepth);
                tempDepth--;
            }
        } 
        return ans;
    }
};