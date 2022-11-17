/**
 * Coin Change
 * 
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 * 
 * Return the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> dp;

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);
        dp[0] = 0;

        for (int coin: coins) {
            if (coin < dp.size()) {
                dp[coin] = 1;
            }
        }

        for (int i = 0; i <= amount; i++) {
            if (dp[i] != -1) {
                continue;
            } else {
                int minAmount = INT_MAX;
                for (int coin: coins) {
                    int cur;
                    if (coin <= i) {
                        cur = dp[i - coin];
                    } else {
                        continue;
                    }

                    if (cur != -1) {
                        minAmount = min(minAmount, cur + 1);
                    }
                }
                if (minAmount != INT_MAX) {
                    dp[i] = minAmount;
                }
            }
        }

        for (int point: dp) {
            cout << point << " ";
        }
        cout << endl;

        return dp[amount];
    }
};

int main() {
    vector<int> coins = { 2 };
    int amount = 3;

    cout << (new Solution()) ->coinChange(coins, amount) << endl;
}