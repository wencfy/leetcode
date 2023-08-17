/**
 * 01 Matrix
 * 
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
 * 
 * The distance between two adjacent cells is 1.
 */

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited = vector<vector<bool>>(mat.size(), vector<bool>(mat.front().size()));
        vector<vector<int>> ret = vector<vector<int>>(mat.size(), vector<int>(mat.front().size()));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.front().size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto dir: dirs) {
                int x = p.first + dir[0];
                int y = p.second + dir[1];
                if (x >= 0 && y >= 0 && x < mat.size() && y < mat.front().size() && !visited[x][y]) {
                    ret[x][y] = ret[p.first][p.second] + 1;
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        return ret;
    }
};