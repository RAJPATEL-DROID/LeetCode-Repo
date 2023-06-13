class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)return 0;
        
        int ladder =nums[0];
        int stairs = nums[0];
        int jumps =1;
        
        for(int level = 1; level < nums.size()-1; level++){
            
            if(level == nums.size() - 1) return jumps;
            if( level + nums[level] > ladder){
                ladder = level + nums[level];
            }
            stairs--;
            if(stairs == 0){
                jumps++;
                stairs = ladder - level;
            }
        }
        return jumps;
    }
};