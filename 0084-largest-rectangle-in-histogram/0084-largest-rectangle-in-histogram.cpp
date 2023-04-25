class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        //        2 PASS  
        // int n = h.size();
//         vector<int> smlLeft(n),smlRight(n);
//         stack<int> s;
        
//         for(int i= 0; i < n; i++){
//             while(!s.empty() && h[s.top()] >= h[i] ){
//                 s.pop();
//             }
//             if(s.empty())smlLeft[i] =0;
//             else smlLeft[i] = s.top() + 1;
//             s.push(i);
//         }
        
//         while(!s.empty())s.pop();
        
        
//         for(int i= n-1;i >=0 ;i--){
//             while(!s.empty() && h[s.top()] >= h[i]){
//                     s.pop();
//             }
//             if(s.empty())smlRight[i] = n-1;
//             else smlRight[i] = s.top() - 1;
//             s.push(i);
//         }
        
//         int ans =0;
//         for(int i=0;i <n;i++){
//             ans = max(ans, h[i]* (smlRight[i] - smlLeft[i]+1 ));
//         }
//         return ans;
        
        // 1 PASS
        int n = h.size();        
         int ans =0;
        stack<int> s;
        
        for(int i =0 ; i <= n; i++){
            while(!s.empty() && (i == n || h[s.top()] >= h[i]) ){
                int height = h[s.top()];
                s.pop();
                int width;
                if(s.empty())width = i;
                else width = i- s.top()-1;
                ans = max(ans,height * width);
            }
            s.push(i);
        }
        
        return ans;
        
    }
};