class Solution {
public:
    bool isIsomorphic(string s, string t) {
//         unordered_map<char,char> m1,m2;
//         for(int i=0;i<s.length();i++){
//             m1[s[i]] =t[i];
//             m2[t[i]] = s[i];
//         }
        
//         for(int i=0;i<s.length();i++){
//             if(m1[s[i]] != t[i])return false;
//             if(m2[t[i]] != s[i])return false;    
//         }
        
//         return true;
        
        
//         The idea is that we need to map a char to another one, for example, "egg" and "add", we need to constract the mapping 'e' -> 'a' and 'g' -> 'd'. Instead of directly mapping 'e' to 'a', another way is to mark them with same value, for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.

// So we use two arrays here m1 and m2, initialized space is 256 (Since the whole ASCII size is 256, 128 also works here). Traverse the character of both s and t on the same position, if their mapping values in m1 and m2 are different, means they are not mapping correctly, returen false; else we construct the mapping, since m1 and m2 are both initialized as 0, we want to use a new value when i == 0, so i + 1 works here.
        
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};