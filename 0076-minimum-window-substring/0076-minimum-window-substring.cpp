class Solution {
public:
    string minWindow(string s, string p) {
         unordered_map<char,int> m;    
        for(int i = 0; i < p.length(); i++){
            m[p[i]]++;
        }
        // get the starting point of min substring
        int start =0;
        int i=0,j=0,count = m.size();
        int minLen =INT_MAX;
        
        while(j < s.length()){
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0)count--;
            }
            if(count ==0)
            {
                while(count == 0){
                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;
                        if(m[s[i]] == 1){
                            count++;
                            if(j - i + 1 < minLen){
                                minLen = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(minLen == INT_MAX)return "";
        return s.substr(start,minLen);
    }
};