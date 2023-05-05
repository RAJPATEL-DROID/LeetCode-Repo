class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int N = c.size();
        int i=0,j=0;
        int total_Sum =0;
        for(int i=0;i < N;i++){
            total_Sum += c[i];
        }
        if(N== k)return total_Sum;
        i=0;
        int win_sum =0;
        while(j != (N-k)){
                  win_sum += c[j++];  
        }
        int ans = total_Sum - win_sum;
        for(int j= (N-k); j < N; j++){
            win_sum -= c[i++];
            win_sum += c[j];
            ans = max(ans,total_Sum - win_sum);
        }
        return ans;
    }
};