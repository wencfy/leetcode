/**
 * Coin Change II
 * 
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * 
 * Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * The answer is guaranteed to fit into a signed 32-bit integer.
 */

#include "iostream"
#include "vector"
using namespace std;

// tle
// class Solution {
//     int ret = 0;
// public:
//     int change(int amount, vector<int>& coins) {
//         dfs(amount, coins, 0);
//         return ret;
//     }

//     void dfs(int amount, vector<int>& coins, int i) {
//         if (!amount) {
//             ret++;
//         } else if (i == coins.size()) {

//         } else {
//             int coin = coins[i];
//             for (int j = 0; coin * j <= amount; j++) {
//                 dfs(amount - coin * j, coins, i + 1);
//             }
//         }
//     }
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(amount + 1));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};
