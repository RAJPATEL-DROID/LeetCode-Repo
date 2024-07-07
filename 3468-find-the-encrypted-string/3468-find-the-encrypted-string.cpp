class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        if(n==1)return s;
        string str = s;
        for(int i=0; i< n; i++){
            s[i] = str[(i+k)%n];
        }

        return s;
    }
};