class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(char c: s){
            m[c]++;
        }
        
        for(char c : t){
            m[c]--;
            if(m[c] == -1)return c;
        }
        return 0;
    }
};