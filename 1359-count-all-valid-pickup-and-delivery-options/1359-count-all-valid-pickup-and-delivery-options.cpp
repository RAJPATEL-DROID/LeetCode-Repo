class Solution {
const int MOD = 1e9 + 7;
public:
    // int countOrders(int n) {
    //     long long count = 1;
    //     for (int i = 2; i <= n; ++i) {
    //         count = (count * (2 * i - 1) * i) % MOD;
    //     }
    //     return (int)count;
    // }
     int countOrders(int n, long res = 1) {
        return n ? countOrders(n - 1, res * (n * 2 - 1) * n % long(1e9+7)) : res;
    }

};