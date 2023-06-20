class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0)return nums;
        vector<int> ans(nums.size(),-1);
        if(2*k + 1> nums.size())return ans;
        
        vector<long long> prefSum(nums.size()+1);
        
        for(int i=0;i< nums.size();i++){
            prefSum[i+1] = nums[i] + prefSum[i];
        }
        
        
        for(int i=k;i < nums.size()-k; i++){
                long long sum =  (prefSum[i+k+1] - prefSum[i-k]);
                int avg = sum/(2*k  + 1);    
                ans[i] = avg;
            }
        return ans;
    }
};