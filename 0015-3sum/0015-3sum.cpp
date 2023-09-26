class Solution {
     vector<vector<int>> k_sum(vector<int> &nums, int start,int target, int k) {
        vector<vector<int>> result{};
        
        if (k >= 2 && k <= nums.size()) {
            if (k == 2) {
                auto end{nums.size() - 1};
                
                while (start < end) {
                    auto left{nums[start]};
                    auto right{nums[end]};
                    auto candidate{left + right};
                    
                    if (candidate == target) {
                        vector<int> res{};
                        res.push_back(left);
                        res.push_back(right);
                        result.push_back(res);
                        
                        for (; start < end && nums[start] == left; ++start) {}
                        for (; end > start && nums[end] == right; --end) {}
                    }
                    else if (candidate > target)
                        --end;
                    else
                        ++start;
                }
            }
            else {
                while (start < nums.size()) {
                    auto left{nums[start]};
                    auto smaller_result{k_sum(nums, start + 1, target - left, k - 1)};
                    for (auto reduced : smaller_result) {
                        vector<int> candidate{};
                        candidate.push_back(left);
                        for (auto elem : reduced)
                            candidate.push_back(elem);
                        
                        result.push_back(candidate);
                    }
                    for (; start < nums.size() && nums[start] == left; ++start) {}
                }
            }
        }
        
        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        return k_sum(nums, 0, 0, 3);
    }
};