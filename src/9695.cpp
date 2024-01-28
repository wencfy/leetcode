#include "iostream"
using namespace std;

class Solution {
public:
    int area = 0;
    int maxArea = 0;
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] && !visited[i][j]) {
                    area = 0;
                    dfs(i, j, visited, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>>& grid) {
        if (visited[x][y]) {
            return ;
        }

        visited[x][y] = true;
        area++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[nx].size()) {
                if (grid[nx][ny] == 1) {
                    dfs(nx, ny, visited, grid);
                }
            }
        }

    }
};