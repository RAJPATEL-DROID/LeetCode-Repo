class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> m;
        int i =0,j=0;
        int n = s.length();
        int len =0;
        while(j < n){
            if(m.find(s[j])  != m.end() && m[s[j]] >=i){
                // cout<<"start"<<i << "end" << j<<'\n';
                len = max(len,((j-1)-i+1));
                // cout<<m[s[j]]<<"\n";
                i = m[s[j]] + 1;
                m.erase(s[j]);
            }
            m[s[j]] = j;
            j++;
        }
        len = max(len,(j-1) - i +1);
        return len;
        
    }
};