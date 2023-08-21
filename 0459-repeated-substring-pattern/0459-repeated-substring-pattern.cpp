class Solution {
public:

    bool repeatedSubstringPattern(string s) {  
        // int n = s.length();
        // for(int i=1;i <= n/2; i++){
        //     if (n % i == 0) {
        //         string pattern = "";
        //         for (int j = 0; j < n / i; j++) {
        //             pattern += s.substr(0, i);
        //         }
        //         if (s == pattern) {
        //             return true;
        //         }
        //     }
        // }
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1) return true;
        return false;
    }
};