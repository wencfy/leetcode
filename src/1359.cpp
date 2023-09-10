class Solution {
public:
    int countOrders(int n) {
        long ret = 1;
        int mod = 7 + 1e9;
        for (int i = 1; i < n; i++) {
            long t = (i * 2 + 1) * (i + 1) % mod;
            ret = ret * t % mod;
        }
        return ret;
    }
};