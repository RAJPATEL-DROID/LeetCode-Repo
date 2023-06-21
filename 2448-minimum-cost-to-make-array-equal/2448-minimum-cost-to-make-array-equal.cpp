class Solution {
    private:
    long long f(vector<int>& nums,vector<int>& cost,int x){
        long long ans = 0;
        
        for(int i=0; i < nums.size(); i++){
            ans += 1L * abs(nums[i] - x) * cost[i];
        }
        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l =1,r=1000000,ans = f(nums,cost,1),x;
        while(l < r){
            x = (l+r) /2;
           long long m1 = f(nums,cost,x),m2 = f(nums,cost,x+1);
            ans = min(m1,m2);
            if( m1 < m2){
                r = x;
            }else{
                l = x + 1;
            }
        }
        return ans;
    }
   
};