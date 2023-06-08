class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& sz) {
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        int n = greed.size();
        int m = sz.size();
        int cnt =0;
        for(int i =0,j=0;i < n && j<m;){
            if(sz[j] >= greed[i] ){
                i++;j++;
                cnt++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};