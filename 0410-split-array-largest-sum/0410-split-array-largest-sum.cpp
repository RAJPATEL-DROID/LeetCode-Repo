class Solution {
public:
    bool possible_MaxSum(vector<int> nums,int k,int mid){
        int cnt_of_subarr = 1;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > mid){
               return false;
            }
            if(sum+ nums[i] > mid ){
                cnt_of_subarr++;
                sum = nums[i];
            }else{
                sum += nums[i];
            }
        }
        return cnt_of_subarr <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate( nums.begin(), nums.end(), 0);
        if(k==nums.size()){
            return lo;
        }
        int ans =0;
        while(lo<=hi){
            int mid = (lo + hi) >> 1;
            if(possible_MaxSum(nums,k,mid)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;  
            }
        }
        return ans;
    }
};