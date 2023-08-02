class Solution {
public:
    void solve(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
      if(temp.size() == nums.size()){
          ans.push_back(temp);
          return;
      }
        
        for(auto it: nums){
            if(find(temp.begin(),temp.end(),it)  == temp.end()){
                temp.push_back(it);
                solve(nums,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp={};
        
        solve(nums,temp,ans);
        
        return ans;
    }
};