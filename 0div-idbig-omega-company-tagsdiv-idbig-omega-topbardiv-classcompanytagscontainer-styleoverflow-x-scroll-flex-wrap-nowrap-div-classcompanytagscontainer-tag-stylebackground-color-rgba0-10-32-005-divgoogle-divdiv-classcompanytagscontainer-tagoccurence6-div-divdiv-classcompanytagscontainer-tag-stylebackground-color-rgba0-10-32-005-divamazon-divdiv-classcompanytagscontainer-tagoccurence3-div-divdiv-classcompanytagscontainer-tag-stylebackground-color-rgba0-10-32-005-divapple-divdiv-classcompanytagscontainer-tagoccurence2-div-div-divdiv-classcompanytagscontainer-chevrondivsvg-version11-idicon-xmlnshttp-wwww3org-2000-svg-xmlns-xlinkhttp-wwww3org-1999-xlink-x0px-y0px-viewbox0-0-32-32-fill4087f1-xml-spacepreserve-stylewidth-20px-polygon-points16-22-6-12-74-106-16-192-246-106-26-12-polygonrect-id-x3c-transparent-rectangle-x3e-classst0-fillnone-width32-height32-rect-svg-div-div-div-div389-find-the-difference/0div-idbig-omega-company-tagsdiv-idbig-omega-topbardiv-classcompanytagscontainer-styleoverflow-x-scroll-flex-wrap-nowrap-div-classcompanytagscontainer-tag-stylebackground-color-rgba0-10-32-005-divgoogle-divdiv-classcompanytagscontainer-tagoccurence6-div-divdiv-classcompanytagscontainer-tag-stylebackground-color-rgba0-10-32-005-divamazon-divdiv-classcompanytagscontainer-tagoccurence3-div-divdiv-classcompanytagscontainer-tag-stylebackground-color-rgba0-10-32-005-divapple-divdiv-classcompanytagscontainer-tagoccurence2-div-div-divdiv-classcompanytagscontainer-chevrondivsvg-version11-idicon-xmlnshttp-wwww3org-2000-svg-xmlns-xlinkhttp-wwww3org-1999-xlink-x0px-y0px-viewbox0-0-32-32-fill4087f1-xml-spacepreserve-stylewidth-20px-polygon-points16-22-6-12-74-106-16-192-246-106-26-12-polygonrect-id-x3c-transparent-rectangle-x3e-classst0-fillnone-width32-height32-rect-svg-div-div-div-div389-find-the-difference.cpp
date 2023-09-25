class Solution {
public:
    char findTheDifference(string s, string t) {
//      BRUTE FORCE   
        // unordered_map<char,int> m;
//         for(char c: s){
//             m[c]++;
//         }
        
//         for(char c : t){
//             m[c]--;
//             if(m[c] == -1)return c;
//         }
//         return 0;
        
        // we can take XOR of char of A and B, All same char will make xor 0 
        // only distinct char will be left in the end.
        char c =0;
        for(char ct : s)c ^= ct;
        for(char ct : t)c ^= ct;
        
        return c;
    }
};