class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // priority_queue<pair<int,int>> maxHeap;
        // maxHeap.push({nums[0],0});
        // int ans = nums[0];

        // for(int i=1;i < nums.size(); i++){
        //     while(i - maxHeap.top().second > k)maxHeap.pop();

        //     int curr = max(0,maxHeap.top().first)  + nums[i];
        //     ans = max(ans,curr);
        //     maxHeap.push({curr,i});
        // }
        // return ans;

        // map<int,int> windows;
        // windows[0] =0;
        // vector<int> dp(nums.size());

        // for(int i=0;i < nums.size(); i++){
        //     dp[i] = nums[i] + windows.rbegin()->first;
        //     windows[dp[i]]++;

        //     if(i >= k){
        //         windows[dp[i-k]]--;
        //         if(windows[dp[i-k]] == 0){
        //             windows.erase(dp[i-k]);
        //         }
        //     }
        // }

        // return *max_element(dp.begin(), dp.end());

        int maxSum =nums[0];
        deque<pair<int,int>> dp;
        dp.push_back({nums[0], 0});

        for(int i=1;i < nums.size();i++){
            if(i - dp.front().second > k){
                dp.pop_front();
            }
            int current  = nums[i];
            if(dp.front().first > 0){
                current += dp.front().first;
            }
            maxSum = max(current,maxSum);

            while(!dp.empty() && dp.back().first < current){
                dp.pop_back();
            }

            dp.push_back({current,i});
        }

        return maxSum;
    }
};