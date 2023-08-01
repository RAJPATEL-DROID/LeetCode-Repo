class Solution {
public:
    void solve(int n,int k,int i,vector<int>& temp,vector<vector<int>>& ans){
        if(temp.size() == k || i == n+1){
            if(temp.size() != k)return;
            ans.push_back(temp);
            return;
        }   
        temp.push_back(i);
        solve(n,k,i+1,temp,ans);
        temp.erase(remove(temp.begin(),temp.end(),i), temp.end());
        solve(n,k,i+1,temp,ans); 
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,k,1,temp,ans);
        
        return ans;
    }
};