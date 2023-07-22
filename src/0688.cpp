/**
 * Knight Probability in Chessboard
 * 
 * On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 * 
 * A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
 * 
 * Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
 * 
 * The knight continues moving until it has made exactly k moves or has moved off the chessboard.
 * 
 * Return the probability that the knight remains on the board after it has stopped moving.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector dp(k + 1, vector (n, vector<double>(n, 0.0)));
        dp[0][row][column] = 1;
        vector<vector<int>> dirs = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

        for (int i = 1; i <= k; i++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (auto dir: dirs) {
                        int tarX = x + dir[0];
                        int tarY = y + dir[1];
                        if (tarX >= 0 && tarY >= 0 && tarX < n && tarY < n) {
                            dp[i][x][y] += dp[i - 1][tarX][tarY] / 8;
                        }
                    }
                }
            }
        }

        double total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                total += dp[k][i][j];
            }
        }

        return total;
    }
};