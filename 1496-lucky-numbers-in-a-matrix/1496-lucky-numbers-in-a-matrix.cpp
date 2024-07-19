class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        set <int> s;
        for(int i=0; i< matrix.size(); i++){

            int min_ele = INT_MAX;
            
            for(int j=0;j < matrix[0].size(); j++){

                min_ele = min(matrix[i][j],min_ele);

            }

            s.insert(min_ele);
        }


        vector<int> ans;
        
        for(int i=0; i< matrix[0].size(); i++){
        
            int max_ele =0;
        
            for(int j=0; j < matrix.size(); j++){
        
               max_ele = max(max_ele, matrix[j][i]);
            }
           
            if(s.find(max_ele) != s.end()){
                // cout<<max_ele<<"\n";
                ans.push_back(max_ele);
            }
        }

        return ans;
    }
};