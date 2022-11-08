/**
 * Number of Islands
 * Given an m x n 2D binary grid grid which represents a map
 * of '1's (land) and '0's (water), return the number of islands.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> isVisited;
    vector<vector<char>> grid;

    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }};

    void init(vector<vector<char>>& grid) {
        int count = grid[0].size();
        isVisited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));
        copy(grid.begin(), grid.end(), back_inserter(this ->grid));
        return ;
    }

    int numIslands(vector<vector<char>>& grid) {
        init(grid);

        int islandCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (island(i, j) && !isVisited[i][j]) {
                    islandCount++;
                    dfs(i, j);
                }
            }
        }

        return islandCount;
    }

    // deep first search
    void dfs(int x, int y) {
        if (!isValid(x, y)) {
            return ;
        }
        if (!island(x, y)) {
            return ;
        }
        if (!isVisited[x][y]) {
            isVisited[x][y] = true;
            for (vector<int> dir: dirs) {
                dfs(x + dir[0], y + dir[1]);
            }
        }
    }

    // judge if (x, y) is valid grid
    bool isValid(int x, int y) {
        return x >= 0
            && y >= 0
            && x < isVisited.size()
            && y < isVisited[0].size();
    }

    bool island(int x, int y) {
        return this ->grid[x][y] == '1';
    }
};

int main() {
    vector<vector<char>> grid = {
        { '1', '1', '1', '1', '0' },
        { '1', '1', '0', '0', '0' },
        { '1', '1', '0', '1', '0' },
        { '1', '0', '1', '1', '0' },
        { '0', '1', '1', '1', '0' },
    };
    Solution *solution = new Solution();
    cout << solution ->numIslands(grid) << endl;
}