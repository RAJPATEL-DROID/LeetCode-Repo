class Solution {
public:
    void generateSet(vector<int>& nums,vector<int>& subset,vector<vector<int> >& ans,int n,int ind){
        if( ind == n){
            ans.push_back(subset);
            return;
        }
        
        generateSet(nums,subset,ans,n,ind+1);
        
        subset.push_back(nums[ind]);
        generateSet(nums,subset,ans,n,ind+1);
        subset.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> subset;
        int n = nums.size();
        generateSet(nums,subset,ans,n,0);
        return ans;
    }
};