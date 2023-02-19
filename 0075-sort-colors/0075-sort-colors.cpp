class Solution {
public:
    void sortColors(vector<int>& nums) {
       
        // Dutch National Flag Algo
        int low =0,mid=0,high = nums.size()-1;
        
        while(mid <= high){
            if(nums[mid]==0){
                swap(nums[low++],nums[mid++]);
            }else if(nums[mid]==2){
                swap(nums[mid],nums[high--]);
            }else{
                mid++;
            }
        }
    }
};