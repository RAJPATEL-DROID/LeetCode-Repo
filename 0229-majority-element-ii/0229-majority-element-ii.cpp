class Solution {
public: 
    vector<int> majorityElement(vector<int>& nums) {
         int target = nums.size()/3;

         unordered_map<int,int> mp;
         for(auto i: nums){
             mp[i]++;
         }
        vector<int> ans;
        for(auto it: mp){
            if(it.second > target)ans.push_back(it.first);
        }

        return ans;

    }
};