class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        vector<int> gr(height.size(),0);
        vector<int> gl(height.size(),0);
        
        //gr
        for(int i=height.size()-1; i >= 0; i--){
            if(!s.empty() && s.top() > height[i]){
                    if(i != height.size()-1 && s.top() < gr[i+1]){
                        gr[i] = gr[i+1];
                    }
                    else{
                        gr[i] = s.top();
                    }
                }else{
                    while(!s.empty() && s.top() <= height[i]){
                         s.pop();
                    }           
                    if(!s.empty()){
                       if(i != height.size()-1 && s.top() < gr[i+1]){
                            gr[i] = gr[i+1];
                        }else{
                            gr[i] = s.top();
                        }
                    }
                }
                s.push(height[i]);
            }
        while(!s.empty()){
            s.pop();
        }
        // gl
        for(int i=0; i< height.size(); i++){
            if(!s.empty() && s.top() > height[i]){
                if(i != 0 && s.top() < gl[i-1]){
                    gl[i] = gl[i-1];
                }
                else  gl[i] = s.top();
            }else{
                while(!s.empty() && s.top() <= height[i]){
                    s.pop();
                }           
                if(!s.empty()){
                    if(i != 0 && s.top() < gl[i-1]){
                        gl[i] = gl[i-1];
                    }else{
                        gl[i] = s.top();
                    }
                }
            }
            s.push(height[i]);
        }
        
        int ans =0;
        for(int i=0; i< height.size(); i++){
            int qnt = min(gr[i],gl[i]);
            ans += (qnt == 0)?0:(qnt-height[i]);
        }
        return ans;
    }
};