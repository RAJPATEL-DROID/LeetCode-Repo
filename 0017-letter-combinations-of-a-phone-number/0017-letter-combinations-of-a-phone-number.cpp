class Solution {
public:
    void GenerateString(string digits,int n,int i,string s,unordered_map<char,char> m,vector<string>& ans){
         if(s.size() == n){
                ans.push_back(s);
                return;
         }
        
        s.push_back(m[digits[i]]);
        GenerateString(digits,n,i+1,s,m,ans);
        s.pop_back();
        
        s.push_back(m[digits[i]] +1);
        GenerateString(digits,n,i+1,s,m,ans);
        s.pop_back();
        
        s.push_back(m[digits[i]]+2);
        GenerateString(digits,n,i+1,s,m,ans);
        s.pop_back();
        
        if( digits[i]  == '7' || digits[i] == '9'){
            s.push_back(m[digits[i]]+3);
            GenerateString(digits,n,i+1,s,m,ans);
            s.pop_back();  
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)return ans;
        unordered_map<char,char> m;
        m['2'] = 'a';
        m['3']='d';m['4'] = 'g';m['5'] = 'j'; m['6'] ='m';m['7'] = 'p';m['8']='t';m['9'] = 'w';
        GenerateString(digits,digits.size(),0,"",m,ans);
        return ans;
    }
};