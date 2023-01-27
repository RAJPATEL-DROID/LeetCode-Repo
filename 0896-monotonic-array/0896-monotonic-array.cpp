class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums[0]<=nums[nums.size()-1]){
            for(int i = 1;i<nums.size()-1;i++){
                    if(nums[i] >= nums[i-1] && nums[i] <= nums[i+1]){
                    continue;       
                }else{
                    return false;
                }
            }
            return true;
        }else{
            for(int i = 1;i<nums.size()-1;i++){
                    if(nums[i] <= nums[i-1] && nums[i] >= nums[i+1]){
                    continue;       
                }else{
                    return false;
                }
            }
            return true;   
        }
        
    }
}; 