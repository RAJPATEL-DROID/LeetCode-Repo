class Solution {
public:
    string removeOuterParentheses(string s) {
        // Obvious Solution
        // stack<char> st;
        // string ans="";
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='(' && st.empty()){
        //         st.push('(');
        //     }else if (s[i] == '('){
        //         ans += "(";
        //         st.push(s[i]);
        //     }else if(s[i]==')'){
        //         st.pop();
        //         if(!st.empty()){
        //             ans += ")";
        //         }
        //     }
        // }
        // return ans;

        // Lee's Solution 
        // Primitive string will have equal number of opened and closed parenthesis.
        string ans="";
        int opened=0;
        for(auto& c:s){
            if(c=='(' && opened++ >0 )ans+=c;
            if(c==')' && opened-- >1 )ans+=c;
        }
        return ans;
    }
};