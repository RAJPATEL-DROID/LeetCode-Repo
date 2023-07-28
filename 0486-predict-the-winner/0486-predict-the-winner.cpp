class Solution {
public:
    int solve(vector<int> & nums,int left, int right){
        if(left == right)return nums[left];
        
        int sumByLeft = nums[left] - solve(nums,left+1,right);
        int sumByRight = nums[right] -  solve(nums,left,right-1);
        
        return max(sumByLeft,sumByRight);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        return solve(nums,0,nums.size()-1) >=0;
    }
};