class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& a, int k) {
//         vector<int>ans;
//         priority_queue<pair<int,int> >pq;
        
//         for(int i=0;i<k;i++){
//             pq.push({a[i],i});
//         }
//         ans.push_back(pq.top().first);
        
//         for(int i=k;i<a.size();i++){
//             pq.push({a[i],i});
           
//             while(i-pq.top().second>=k)pq.pop();
           
//             ans.push_back(pq.top().first);
//         }
//         return ans;

//     }
// };