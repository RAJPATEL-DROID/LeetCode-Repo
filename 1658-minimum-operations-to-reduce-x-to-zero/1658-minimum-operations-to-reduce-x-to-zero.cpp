class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int a:nums)sum += a;
        
        int currSum =0, maxLen = -1;
        for(int l=0,r=0; r < nums.size();r++){
            currSum += nums[r];
            while(l <= r && currSum > sum  - x)currSum -= nums[l++];
            if(currSum == sum - x)maxLen = max(maxLen,r-l+1);
        }
        return maxLen == -1 ? -1 :nums.size()-maxLen;
    }
};