class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> ans;
        // vector<int> dp(n+1,-1);
        // dp[0] = 0; 
        // dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] = 1;
        // for(int i=0;i <= n;i++){
        //     int cnt =0;
        //     int div = i/4;
        //     int modulo = i% 4;
        //     if(div%2 == 0){
        //         cnt++;
        //     }else{
        //         cnt += dp[div];
        //     }            
        //     cnt += dp[modulo];
        //     if(dp[i] == -1)dp[i] = cnt;
        //     ans.push_back(cnt);
        // }
        // return ans;
        
        
        // n+1 as we are going to count from 0 to n
        vector<int> t(n+1);
        
        // t[0] will be 0 beacuse 0 has count of set bit is 0;
        t[0] = 0;
        
        // we can compute current set bit count using previous count
        // as x/2 in O(1) time
        
        // i%2 will be 0 for even number and 1 for odd number
        
        for(int i = 1; i<=n; ++i)
            t[i] = t[i/2] + i%2;
        
        return t;
    }
};