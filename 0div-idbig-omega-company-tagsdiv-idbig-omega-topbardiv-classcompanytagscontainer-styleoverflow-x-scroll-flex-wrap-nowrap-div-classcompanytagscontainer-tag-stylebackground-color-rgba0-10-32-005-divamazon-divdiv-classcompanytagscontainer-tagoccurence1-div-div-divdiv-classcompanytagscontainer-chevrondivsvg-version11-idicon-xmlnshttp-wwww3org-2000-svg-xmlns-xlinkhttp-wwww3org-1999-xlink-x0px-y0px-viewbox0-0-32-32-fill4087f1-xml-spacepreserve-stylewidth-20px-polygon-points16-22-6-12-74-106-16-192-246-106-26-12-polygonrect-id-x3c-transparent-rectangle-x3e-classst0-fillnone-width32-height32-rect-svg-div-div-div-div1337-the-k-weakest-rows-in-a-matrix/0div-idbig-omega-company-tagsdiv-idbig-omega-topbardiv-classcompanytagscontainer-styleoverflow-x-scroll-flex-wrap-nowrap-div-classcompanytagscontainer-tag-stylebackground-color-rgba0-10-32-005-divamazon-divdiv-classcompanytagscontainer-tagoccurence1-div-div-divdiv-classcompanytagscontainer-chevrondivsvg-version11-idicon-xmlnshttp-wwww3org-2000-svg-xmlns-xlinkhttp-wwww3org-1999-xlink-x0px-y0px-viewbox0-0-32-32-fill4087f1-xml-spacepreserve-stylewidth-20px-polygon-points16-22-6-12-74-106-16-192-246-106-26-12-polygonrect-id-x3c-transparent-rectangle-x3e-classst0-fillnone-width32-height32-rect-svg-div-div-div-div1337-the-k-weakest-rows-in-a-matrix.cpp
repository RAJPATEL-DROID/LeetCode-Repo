class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         int m = mat.size();
//         int n = mat[0].size();
//         vector<int> numSol(m);
//         for(int i=0; i< m; i++){
//             int sold =0;
//             for(int j=0; j < n;j++){
//                 if(mat[i][j] == 1)sold++;
//                 if(mat[i][j] == 0)break;
//             }
//             numSol[i] = sold;
//         }
        
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
//         for(int i=0;i<m;i++){
//             pq.push({numSol[i],i});
//         }
//         vector<int> ans;
//         while(k){
//             ans.push_back(pq.top().second);
//             pq.pop();
//             k--;
//         }
//         return ans;
        
        int n=mat[0].size();
        for(int i=0; i<mat.size(); i++){
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> ans(k);
        for(int i=0; i<k; i++){
            ans[i]=mat[i][n];            
        }
        return ans;
    }
};