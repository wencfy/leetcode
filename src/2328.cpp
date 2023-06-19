/**
 * Number of Increasing Paths in a Grid
 * 
 * You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.
 * 
 * Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the retwer may be very large, return it modulo 109 + 7.
 * 
 * Two paths are considered different if they do not have exactly the same sequence of visited cells.
 */

#include "iostream"
using namespace std;

// Define f(i, j) as the number of increasing paths starting from cell (i, j).
// f(i, j) = grid[i][j] < grid[i + 1][j] ? f(i + 1, j) : 0
//         + grid[i][j] < grid[i - 1][j] ? f(i - 1, j) : 0
//         + grid[i][j] < grid[i][j + 1] ? f(i, j + 1) : 0
//         + grid[i][j] < grid[i][j - 1] ? f(i, j - 1) : 0
class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> grid;
    const int modulo = 1000000007;

public:
    int countPaths(vector<vector<int>>& grid) {
        dp = vector<vector<int>>(grid.size(), vector<int>(grid.front().size(), -1));
        this->grid = grid;

        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (dp[i][j] != -1) {
                    ret = (ret + dp[i][j]) % modulo;
                } else {
                    ret = (ret + solve(i, j)) % modulo;
                }
            }
        }

        for (vector<int> line: dp) {
            for (int i: line) {
                cout << i << " ";
            }
            cout << endl;
        }

        return ret;
    }

    int solve(int x, int y) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int cur = grid[x][y];
        dp[x][y] = (isValid(x + 1, y) && cur < grid[x + 1][y] ? solve(x + 1, y) : 0)
                 + (isValid(x - 1, y) && cur < grid[x - 1][y] ? solve(x - 1, y) : 0)
                 + (isValid(x, y + 1) && cur < grid[x][y + 1] ? solve(x, y + 1) : 0)
                 + (isValid(x, y - 1) && cur < grid[x][y - 1] ? solve(x, y - 1) : 0)
                 + 1;
        dp[x][y] %= modulo;
        
        return dp[x][y];
    }

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < dp.size() && y < dp.front().size();
    }
};