class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j =0;
        bool flag = false;
        for(int i=0;i< pushed.size(); i++){
            s.push(pushed[i]);
            
            if(popped[j] != s.top()){
                if(distance(pushed.begin(), find(pushed.begin(), pushed.end(), popped[j])) < i){
                    flag = true;
                    break;
                }else{
                    continue;
                }
            }else{
                // cout<<popped[j] << " " << s.top()<<" \n";
                while(j < pushed.size() && !s.empty() && s.top() == popped[j]){
                    // cout<<popped[j] << " " << s.top()<<" \n";
                    s.pop();
                    j++;
                }
            }
        }
        while(!s.empty() && j < popped.size()){
            if(s.top() != popped[j]){
                flag = true;
                break;
            }else{
               j++; 
            }
        }
        if(flag== true)return false;
        return true;
    }
};