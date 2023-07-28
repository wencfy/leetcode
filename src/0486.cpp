/**
 * Predict the Winner
 * 
 * You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
 * 
 * Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
 * 
 * Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(nums.size()));

        long long s = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = nums[i];
            if (i + 1 < nums.size()) {
                dp[i][i + 1] = max(nums[i], nums[i + 1]);
            }
            s += nums[i];
        }

        for (int d = 2; d < nums.size(); d++) {
            for (int i = 0; i + d < nums.size(); i++) {
                // dp[i][i + d]
                dp[i][i + d] = max(
                    nums[i] + min(dp[i + 1][i + d - 1], dp[i + 2][i + d]),
                    nums[i + d] + min(dp[i][i + d - 2], dp[i + 1][i + d - 1])
                );
            }
        }

        return dp[0][nums.size() - 1] >= s - dp[0][nums.size() - 1];
    }
};