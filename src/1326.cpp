#include "iostream"
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> rangesByFirst = vector<vector<int>>();
        for (int i = 0; i <= n; i++) {
            rangesByFirst.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(rangesByFirst.begin(), rangesByFirst.end(), [](auto a, auto b){
            return a[0] < b[0];
        });

        vector<int> dp = vector<int>(n + 1, n + 2);
        dp[0] = 0;

        for (int i = 0; i <= n; i++) {
            int l = max(rangesByFirst[i][0], 0);
            int r = min(rangesByFirst[i][1], n);
            for (int j = l; j <= r; j++) {
                if (dp[j] + 1 < dp[r]) {
                    dp[r] = dp[j] + 1;
                }
            }
        }

        return dp[n] == n + 2 ? -1 : dp[n];
    }
};