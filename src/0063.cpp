/**
 * Unique Paths II
 * 
 * You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 * 
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
 * 
 * Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * 
 * The testcases are generated so that the answer will be less than or equal to 2 * 109.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long>> dp = vector<vector<long>>(obstacleGrid.size(), vector<long>(obstacleGrid.front().size(), 0));
        if (!obstacleGrid[0][0]) {
            dp[0][0] = 1;
        }
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp.front().size(); j++) {
                if (obstacleGrid[i][j] != 1) {
                    if (i - 1 >= 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j - 1 >= 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp.back().back();
    }
};