#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto a, auto b){
            return a[0] < b[0];
        });
        vector<int> dp(pairs.size(), 1);
        int ret = 0;
        int cur = pairs.size() - 1;
        for (int i = pairs.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < pairs.size(); j++) {
                if (pairs[i][1] < pairs[j][0]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};