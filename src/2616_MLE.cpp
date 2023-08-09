#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        // MLE
        vector<vector<int>> dp = vector<vector<int>>(nums.size() + 1, vector<int>(p + 1));

        for (int j = 1; j <= p; j++) {
            for (int i = nums.size() - 2 * j; i <= nums.size(); i++) {
                dp[i][j] = INT_MAX;
            }
        }

        for (int j = 1; j <= p; j++) {
            for (int i = nums.size() - 2 * j; i >= 0; i--) {
                dp[i][j] = min(
                    dp[i + 1][j],
                    max(abs(nums[i] - nums[i + 1]), dp[i + 2][j - 1])
                );
            }
        }

        // for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i] << " ";
            // cout << dp[i][1] << " ";
        // }
        // cout << endl;

        return dp[0][p];
    }
};