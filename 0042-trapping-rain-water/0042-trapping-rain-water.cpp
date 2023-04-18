class Solution {
public:
    int trap(vector<int>& arr) {
        // Using Stack
//         stack<int> s;
//         int water =0;
//         int current =0;
//         while( current < height.size()){
//             while(!s.empty() && height[current] > height[s.top()]){
//                 int top = s.top();
//                 s.pop();
        
        // Break if there are no block on left of current block
//                 if(s.empty())break;   
        
                
                
              // we find the distance between curr element & element in left
//                 int distance = current- s.top()-1;
               
// We find the minimum block from blocks of max height from left and right
// then we calculate how much water the container will carry between that
// block and current block
        
//                 int bounded_height = min(height[current],height[s.top()]) - height[top];
//                 water += bounded_height * distance;
//             }
//             s.push(current++);
//         }
//         return water;

        // Two Pointer Approach
//         int i=0,j = height.size()-1,  mi = 0,mx=0;
//         int ans =0;
//         while(i <= j){
//             mi = min(height[i],height[j]);
                        
//             mx = max(mx,mi);
            
//             ans += mx-mi;
            
//             if(height[i] < height[j])i++;
//             else j--;
//         }
    
//         return ans;
        
        // Simple O(n) ith two loops iterating
        int n = arr.size();
        long long total_water = 0;
        int lmax[n];
        int rmax[n];
        
        lmax[0] = arr[0];
        for(int i=1; i<= n-1; i++)
            lmax[i] = max(lmax[i-1],arr[i]);
            
        rmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--)
            rmax[i] = max(rmax[i+1],arr[i]);
            
        for(int i=1; i<=n-1; i++)
        total_water = total_water + (min(lmax[i],rmax[i])-arr[i]);
        return total_water;
    
    }
};