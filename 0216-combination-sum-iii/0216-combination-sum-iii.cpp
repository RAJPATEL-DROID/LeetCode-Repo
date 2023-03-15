class Solution {
public:
    void GenerateSum(int i,int k,int n,vector<vector<int>> & ans,vector<int>& temp){
        if(i > 9){
            if(temp.size() == k){
                int s =0;
                for(int a:temp){
                    s += a;
                }
                if(s == n)ans.push_back(temp);
            }
            return;
        }
        if(temp.size() == k){
                int s =0;
                for(int a:temp){
                    s += a;
                }
                if(s == n)ans.push_back(temp);
                return;
        }

        GenerateSum(i+1,k,n,ans,temp);
        
        temp.push_back(i);
        GenerateSum(i+1,k,n,ans,temp);
        temp.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        GenerateSum(1,k,n,ans,temp);
        return ans;
    }
};