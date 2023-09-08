class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        for(int i=0;i < n;i++){
            vector<int> temp;
            for(int j=0;j <= i; j++){
                int tmp =0;
                if(i == 0){
                    temp.push_back(1);
                    break;
                }
                
                if(i-1 >= 0 && j-1 >= 0)tmp += ans[i-1][j-1];
                if(i-1 >=0 && j < i)tmp += ans[i-1][j];
                temp.push_back(tmp);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};