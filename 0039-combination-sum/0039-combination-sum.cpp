class Solution {
public:
    void f(int ind,vector<int>& arr,int target,vector<vector<int>>& ans,vector<int>& temp){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            f(ind,arr,target-arr[ind],ans,temp);
            temp.pop_back();
        }
        
        f(ind+1,arr,target,ans,temp);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int> > ans;
        f(0,candidates,target,ans,temp);
        return ans;
    }
};