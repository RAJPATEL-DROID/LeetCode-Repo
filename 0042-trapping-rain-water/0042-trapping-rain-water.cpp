class Solution {
public:
    int trap(vector<int>& height) {
        // Using Stack
//         stack<int> s;
//         int water =0;
//         int current =0;
//         while( current < height.size()){
//             while(!s.empty() && height[current] > height[s.top()]){
//                 int top = s.top();
//                 s.pop();
                
//                 if(s.empty())break;   // that is there are no block on left of current block
                
                
//                 // we find the distance between curr element element in left
//                 int distance = current- s.top()-1;
                
//                 // We find the minimum block from blocks of max height from left and right
//                 // then we calculate how much water the container will carry between that
//                 // block and current block
//                 int bounded_height = min(height[current],height[s.top()]) - height[top];
//                 water += bounded_height * distance;
//             }
//             s.push(current++);
//         }
//         return water;

        // Two Pointer Approach
        int i=0,j = height.size()-1,  mi = 0,mx=0;
        int ans =0;
        while(i <= j){
            mi = min(height[i],height[j]);
                        
            mx = max(mx,mi);
            
            ans += mx-mi;
            
            if(height[i] < height[j])i++;
            else j--;
        }
    
        return ans;
    
    }
};