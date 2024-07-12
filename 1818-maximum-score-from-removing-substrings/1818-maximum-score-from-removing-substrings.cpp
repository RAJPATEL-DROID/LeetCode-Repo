class Solution {
public:
    int removePairs(string &s,string target){
        int curr_ind =0,count =0;

        for(char c: s){
            s[curr_ind] = c;
            curr_ind++;
            if(curr_ind >= 2 && s[curr_ind -1 ] == target[1] && s[curr_ind-2] == target[0]){
                count++;
                curr_ind -=2;
            }
        }

        s.resize(curr_ind);
        return count;
    }
    int maximumGain(string s, int x, int y) {
        int res=0;
        string top,bot;

        int grt,less;

        if(x> y){
            top = "ab";
            grt=x;
            bot="ba";
            less =y;
        }else{
            top="ba";
            grt=y;
            bot ="ab";
            less=x;
        }

        res += removePairs(s,top) * grt;
        res += removePairs(s,bot) * less;

        return res;
    }
};