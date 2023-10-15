class Solution {
public:
    vector<vector<int>> memo;
    int MOD = 1e9+7;
    int arrLen;
    int dp(int curr,int remains){
        if(remains == 0){
            return curr == 0;
        }

        if(memo[curr][remains] != -1){
            return memo[curr][remains];
        }

        int ans = dp(curr,remains-1);
        if(curr > 0){
            ans =(ans + dp(curr-1,remains-1)) % MOD;
        }
        if(curr < arrLen - 1){
            ans = (ans + dp(curr+1,remains-1)) % MOD;
        }

    return memo[curr][remains] = ans;

    }
    int numWays(int steps, int arrLen) {
        arrLen= min(arrLen,steps);
        this->arrLen = arrLen;
        memo = vector(arrLen,vector(steps+1,-1));
        return dp(0,steps);
    }
};