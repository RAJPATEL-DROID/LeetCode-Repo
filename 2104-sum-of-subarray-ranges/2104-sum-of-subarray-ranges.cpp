class Solution {
public:
    long long subArrayRanges(vector<int>& A) {
        long res = 0, n = A.size(), j, k;
        stack<int> s;\
            // Find the Sum of Subarrays of Minimums -> See the Question with samename
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] > (i == n ? -2e9 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res -= (long)A[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        
        s = stack<int>();
        
        // Find the Sum of  Subarray of Maximums
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] < (i == n ? 2e9 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res += (long)A[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return res;
    }
};