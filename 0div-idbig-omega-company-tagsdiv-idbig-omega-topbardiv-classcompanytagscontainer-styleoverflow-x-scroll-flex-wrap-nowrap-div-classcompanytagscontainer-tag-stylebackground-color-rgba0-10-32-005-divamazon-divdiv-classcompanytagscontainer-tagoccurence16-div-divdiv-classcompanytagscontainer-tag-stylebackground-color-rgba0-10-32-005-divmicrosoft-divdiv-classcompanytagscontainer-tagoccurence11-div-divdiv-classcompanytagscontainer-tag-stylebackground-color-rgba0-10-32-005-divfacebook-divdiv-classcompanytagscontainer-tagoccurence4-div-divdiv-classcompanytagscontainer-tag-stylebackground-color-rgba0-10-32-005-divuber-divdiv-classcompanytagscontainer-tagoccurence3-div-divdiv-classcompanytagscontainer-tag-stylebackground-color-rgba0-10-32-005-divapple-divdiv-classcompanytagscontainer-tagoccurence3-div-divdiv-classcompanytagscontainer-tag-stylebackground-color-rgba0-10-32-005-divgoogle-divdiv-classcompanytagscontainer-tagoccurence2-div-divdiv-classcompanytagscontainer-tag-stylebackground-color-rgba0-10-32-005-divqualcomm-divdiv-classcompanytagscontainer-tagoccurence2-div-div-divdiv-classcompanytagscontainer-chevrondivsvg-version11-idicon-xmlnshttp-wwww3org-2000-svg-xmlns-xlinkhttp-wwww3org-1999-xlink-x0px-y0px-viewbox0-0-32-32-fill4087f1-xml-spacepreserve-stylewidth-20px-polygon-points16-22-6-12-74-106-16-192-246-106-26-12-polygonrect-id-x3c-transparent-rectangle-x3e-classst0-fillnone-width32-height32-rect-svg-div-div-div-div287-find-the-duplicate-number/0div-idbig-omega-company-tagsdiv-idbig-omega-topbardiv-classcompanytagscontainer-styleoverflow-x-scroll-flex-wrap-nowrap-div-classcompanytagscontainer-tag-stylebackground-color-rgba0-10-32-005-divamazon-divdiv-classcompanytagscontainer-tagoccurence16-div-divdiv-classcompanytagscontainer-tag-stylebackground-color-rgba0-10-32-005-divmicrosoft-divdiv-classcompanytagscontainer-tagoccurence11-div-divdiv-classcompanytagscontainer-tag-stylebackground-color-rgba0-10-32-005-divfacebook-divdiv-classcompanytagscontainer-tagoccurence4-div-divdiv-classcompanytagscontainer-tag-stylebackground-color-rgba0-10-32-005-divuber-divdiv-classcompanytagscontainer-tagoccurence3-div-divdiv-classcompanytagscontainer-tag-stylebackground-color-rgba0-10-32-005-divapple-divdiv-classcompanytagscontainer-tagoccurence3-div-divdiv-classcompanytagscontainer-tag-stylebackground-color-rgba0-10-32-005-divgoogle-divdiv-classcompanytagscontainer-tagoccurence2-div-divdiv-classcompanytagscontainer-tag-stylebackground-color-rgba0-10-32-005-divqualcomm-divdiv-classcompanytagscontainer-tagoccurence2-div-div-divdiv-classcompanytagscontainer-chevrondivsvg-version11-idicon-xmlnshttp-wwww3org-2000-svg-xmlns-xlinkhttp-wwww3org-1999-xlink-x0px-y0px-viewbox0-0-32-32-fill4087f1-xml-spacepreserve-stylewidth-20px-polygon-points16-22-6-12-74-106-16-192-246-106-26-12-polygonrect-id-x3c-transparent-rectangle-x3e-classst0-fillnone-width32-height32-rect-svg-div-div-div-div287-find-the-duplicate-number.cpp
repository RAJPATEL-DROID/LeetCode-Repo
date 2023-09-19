class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // O(1) Space
        for(int i=0; i< nums.size();){
            if(nums[i] == i+1){
                ++i;
            }    
            else if(int &n = nums[i];nums[n-1] == n){
                return n;
            }else{
                swap(n,nums[n-1]);
            }
        }
        
        return 0;
        
        // O(1) Space and O(n) Time
//         int slow = nums[0];
//         int fast = nums[slow];
        
//         while(slow != fast){
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }
        
//         slow = 0;
//         while(slow != fast){
//             slow = nums[slow];
//             fast = nums[fast];
//         }
        
//         return slow;
        
    }
};