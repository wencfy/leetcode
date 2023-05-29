/**
 * Shortest Bridge
 * 
 * You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
 * An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
 * You may change 0's to 1's to connect the two islands to form one island.
 * Return the smallest number of 0's you must flip to connect the two islands.
 */

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
private:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> visited;
    vector<vector<int>> grid;
    queue<pair<int, int>> q;

public:
    int shortestBridge(vector<vector<int>>& grid) {
        this->visited = vector<vector<int>>(grid.size(), vector<int>(grid.front().size(), 0));
        this->grid = grid;

        // 1st island
        int i, j, b = 1;
        for (i = 0; i < grid.size() && b; i++) {
            for (j = 0; j < grid.front().size() && b; j++) {
                if (grid[i][j] == 1) {
                    b = 0;
                }
            }
        }

        visited[--i][--j] = 1;
        dfs(i, j);

        int ret = 0;
        while (!q.empty() && !ret) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4 && !ret; i++) {
                int vx = x + dirs[i][0];
                int vy = y + dirs[i][1];
                if (isLegal(vx, vy) && !visited[vx][vy]) {
                    if (grid[vx][vy]) {
                        ret = visited[x][y] - 1;
                    } else {
                        visited[vx][vy] = visited[x][y] + 1;
                        q.push(pair<int, int>(vx, vy));
                    }
                }
            }
        }

        return ret;
    }

    bool isLegal(int x, int y) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }

    void dfs(int x, int y) {
        q.push(pair<int, int>(x, y));
        for (int i = 0; i < 4; i++) {
            int vx = x + dirs[i][0];
            int vy = y + dirs[i][1];
            if (isLegal(vx, vy) && !visited[vx][vy] && grid[vx][vy]) {
                visited[vx][vy] = 1;
                dfs(vx, vy);
            }
        }
    }
};

int main() {
    vector<vector<int>> grid = {
        {0,0,0,0,0},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,1,0,0,1},
        {1,0,0,0,1}
    };

    cout << (new Solution()) ->shortestBridge(grid) << endl;
}