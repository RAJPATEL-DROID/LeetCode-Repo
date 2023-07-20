class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0,majority=nums[0];
        for(auto i : nums){
            // cout<<i<<" "<<count<<"\n";
            if(i == majority) {
                count++;
                // cout<<coun.t<<"\n";
            }else count--;
            if(count == 0){majority=i;count=1;}
        }
        return majority;
        
        // Majority element is alway there so no need to check
//      count =0;
        // for(auto i : nums){
//             if(i == majority)count++;
//         }
        
//         if(count > floor(nums.size()/2))return majority;
//         return -1;
    }
};