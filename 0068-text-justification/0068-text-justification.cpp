class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        vector<string> ans,line;
        string s;
        
        int len =0;
        for(int i=0;i< words.size(); ++i){
            if(len + line.size()  + words[i].size() <= L){
                len += words[i].size();
                line.push_back(words[i]);
            }
            else{
                
                if(line.size() == 1){
                    s = line[0];
                    s.append(L-s.size(),' ');
                    ans.push_back(s);
                }
                else if(line.size() > 1){
                    
                    int div = (L - len)/(line.size() -1);
                    int mod = (L - len)%(line.size() -1);
                    
                    s = line[0];
                    
                    for(int j=1; j < line.size(); ++j){
                        if(j <= mod)s.append(div+1,' ');
                        else s.append(div,' ');
                        s += line[j];
                    }
                    ans.push_back(s);
                }
                
                line.clear();
                line.push_back(words[i]);
                len = words[i].size();
            }
        }
        
        s = line[0];
        for(int j=1;j<line.size();j++){
            s += ' '+ line[j];
        }
        s.append(L - s.size(),' ');
        ans.push_back(s);
        return ans;
    }
};