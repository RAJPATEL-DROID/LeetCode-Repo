class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i <= n;i++){
            int temp = i;
            int cnt= 0;
            while(temp != 0){
                if(temp&1){
                    cnt++;
                }
                temp = temp>>1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};