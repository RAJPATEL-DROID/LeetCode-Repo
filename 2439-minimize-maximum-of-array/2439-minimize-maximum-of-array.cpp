class Solution {
public:
//     int minimizeArrayValue(vector<int>& nums) {
//         long long answer = 0,preSum = 0;
        
//         for(int i=0; i< nums.size(); i++){
//             preSum += nums[i];
//             answer = max(answer, (preSum+i)/(i+1) );
//         }
//         return answer;
//     }

    // Binary search
    bool check(vector<long long> nums,int t){
        int n = nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i]>t){
                nums[i-1]+=(nums[i]-t);
            }
        }
        return nums[0]<=t;
    }
    
    
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0;
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;
        vector<long long> v;
        for(auto x:nums){
            v.push_back(x);
        }
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(v,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};