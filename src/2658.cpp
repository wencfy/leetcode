#include "iostream"
#include "queue"
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> vis(grid.size(), vector<int>(grid.front().size(), 0));

        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    int c = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        c += grid[p.first][p.second];

                        for (int d = 0; d < 4; d++) {
                            int x = p.first + dirs[d][0];
                            int y = p.second + dirs[d][1];

                            if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] && !vis[x][y]) {
                                q.push({x, y});
                                vis[x][y] = 1;
                            }
                        }
                    }
                    ret = max(c, ret);
                }
            }
        }
        return ret;
    }
};