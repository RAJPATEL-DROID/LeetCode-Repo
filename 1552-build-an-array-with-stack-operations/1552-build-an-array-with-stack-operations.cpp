class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        string push = "Push";
        string pop = "Pop";
        int ptr =0;
        for(int i=1;i <= n;i++){
            if(st.empty()){
                    st.push(i);
                    ans.push_back(push);
                    if(target[ptr] == i){
                        ptr++;
                    }
                        
            }else{
                if(i == target[ptr]){
                    if(ptr == 0){
                        while(!st.empty()){
                            st.pop();
                            ans.push_back(pop);
                        }
                    }
                    while(!st.empty() &&  st.top() != target[ptr-1]){
                        st.pop();
                        ans.push_back(pop);
                    }
                    st.push(i);
                    ans.push_back(push);
                    ptr++;
                    if(ptr == target.size())break;
                }else{
                    st.push(i);
                    ans.push_back(push);
                }
            }
            if(ptr == target.size())break;
        }

        return ans;
    }
};