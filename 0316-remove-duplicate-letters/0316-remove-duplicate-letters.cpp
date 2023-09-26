class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0);
        for(int i=0; i< s.length(); i++){
            lastIndex[s[i]- 'a'] = i;
        }

        vector<bool> vis(26,false);
        stack<char> st;

        for(int i=0; i< s.size(); i++){
            int curr = s[i] - 'a';
            if(vis[curr])continue;

            while( st.size() > 0  && st.top() > s[i] && i < lastIndex[st.top()- 'a']){
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[curr] = true;
        }
        string ans ="";
        while(st.size() > 0){
            ans += st.top();
            st.pop();
        }   
        reverse(ans.begin(),ans.end());
        return ans;

    }
};