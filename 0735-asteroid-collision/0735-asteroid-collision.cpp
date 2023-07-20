class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        //          Monotonic Stack
        vector<int> ans;
        stack<int> s;
        int n = ast.size();
        for(int i=0; i < n;i++){
            if(ast[i] > 0){
                s.push(ast[i]);
            }else{
                int flag =1;
                while(!s.empty() && abs(ast[i]) - s.top() >= 0){
                    if(abs(ast[i]) - s.top() == 0){
                        flag =0;
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                // If all the previous ast moving right are destroyed,
                // then push our curr ast in stack
                if(s.empty() && flag){
                    ans.push_back(ast[i]);
                }
            } 
        }
        vector<int> temp;
        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }
        
        for(int i= temp.size() - 1 ; i >= 0; i--){
            ans.push_back(temp[i]);
        }
        return ans;
       
    }
};