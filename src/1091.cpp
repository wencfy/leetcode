/**
 * Shortest Path in Binary Matrix
 * 
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
 *  1. All the visited cells of the path are 0.
 *  2. All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
 */

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {
        { 1, 1 },
        { 1, 0 },
        { 1, -1 },
        { 0, 1 },
        { 0, -1 },
        { -1, 1 },
        { -1, 0 },
        { -1, -1 },
    };

    queue<vector<int>> q;

    vector<vector<int>> visited;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        visited.resize(grid.size(), vector<int> (grid.size(), 0));
        
        int n = grid.size();
        if (!grid[0][0]) {
            q.push({ 0, 0 });
            visited[0][0] = 1;
        }
        while (!q.empty()) {
            vector<int> curIndex = q.front();
            // cout << curIndex[0] << ", " << curIndex[1] << endl;
            q.pop();
            if (curIndex[0] == n - 1 && curIndex[1] == n - 1) {
                return visited[curIndex[0]][curIndex[1]];
            }
            for (vector<int> dir: dirs) {
                // cout << "dir" << dir[0] << dir[1] << " " << isValid(curIndex, dir, n) << endl;
                if (isValid(curIndex, dir, n)
                 && !grid[curIndex[0] + dir[0]][curIndex[1] + dir[1]]
                 && !visited[curIndex[0] + dir[0]][curIndex[1] + dir[1]]) {
                    q.push({
                        curIndex[0] + dir[0],
                        curIndex[1] + dir[1],
                    });
                    visited[curIndex[0] + dir[0]][curIndex[1] + dir[1]]
                        = visited[curIndex[0]][curIndex[1]] + 1;
                }
            }
        }
        return -1;
    }

    bool isValid(vector<int> curIndex, vector<int> dir, int n) {
        return curIndex[0] + dir[0] >= 0
            && curIndex[0] + dir[0] < n
            && curIndex[1] + dir[1] >= 0
            && curIndex[1] + dir[1] < n;
    }
};

int main() {
    vector<vector<int>> grid = { { 0, 0, 0 }, { 1, 1, 0 }, { 1, 1, 0 } };
    cout << (new Solution()) ->shortestPathBinaryMatrix(grid) << endl;
}