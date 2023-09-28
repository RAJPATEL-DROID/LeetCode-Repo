class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j= 0;
        while(j < nums.size()){
            // cout<<"j : "<<j<<"\n";
            if(nums[j] % 2 == 0){
                // cout<<nums[i]<<" "<<nums[j]<<"\n";
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        return nums;
    }
};