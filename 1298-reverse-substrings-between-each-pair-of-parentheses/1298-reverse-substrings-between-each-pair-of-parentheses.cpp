class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> res;
        stack<int> st;
        
        for(int i=0; i< s.size();i++){
            if(s[i] == '('){
                st.push(res.size());
            }else if(s[i] ==')'){
                int start_ind = st.top();
                st.pop();
                reverse(res.begin() + start_ind, res.end());
            }else{
                res.push_back(s[i]);
            }
        }

        return string(res.begin(),res.end());
    }
};