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
        
//         if(!k || !n){
//             if(!k && !n){ // Means we got our sum
//                 ans.push_back(temp);
//             }
//             return;
//         }
        
//         for(int j=i ;j <= min(9,n); j++){
//             temp.push_back(j);
//             GenerateSum(j+1,k-1,n-j,ans,temp);
//             temp.pop_back();
//         }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        GenerateSum(1,k,n,ans,temp);
        return ans;
    }
};