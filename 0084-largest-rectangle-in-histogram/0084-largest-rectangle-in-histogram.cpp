class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> smlLeft(n),smlRight(n);
        stack<int> s;
        
        for(int i= 0; i < n; i++){
            while(!s.empty() && h[s.top()] >= h[i] ){
                s.pop();
            }
            if(s.empty())smlLeft[i] =0;
            else smlLeft[i] = s.top() + 1;
            s.push(i);
        }
        
        while(!s.empty())s.pop();
        
        
        for(int i= n-1;i >=0 ;i--){
            while(!s.empty() && h[s.top()] >= h[i]){
                    s.pop();
            }
            if(s.empty())smlRight[i] = n-1;
            else smlRight[i] = s.top() - 1;
            s.push(i);
        }
        
        int ans =0;
        for(int i=0;i <n;i++){
            ans = max(ans, h[i]* (smlRight[i] - smlLeft[i]+1 ));
        }
        return ans;
        
    }
};