class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       int n = bloomDay.size(),  l= 1, r = 1e9;
        if ((long)m*k>n)return -1;
        while (l<r) {
            int mid = (l + r) / 2, flow = 0, bouq = 0;
            for (int j = 0; j < n; ++j) {
                if (bloomDay[j] > mid) {
                    flow = 0;
                } else if (++flow >= k) {
                    bouq++;
                    flow = 0;
                }
            }
            if (bouq < m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};