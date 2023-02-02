class Solution {
public:
    bool isAnagram(string a, string t) {
        if(a.length() !=  t.length())return false;
        
        unordered_map<char,int> m;
        for(int i=0;i<a.length();i++){
            m[a[i]]++;    
        }
        for(int i=0;i<a.length();i++){
            m[t[i]]--;
        }
        for(int i=0;i<a.length();i++){
            if(m[a[i]] != 0)return false;
        }
        return true;
    }
};