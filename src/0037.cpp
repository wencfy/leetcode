#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    vector<set<char>> line;
    vector<set<char>> row;
    vector<set<char>> grid;

    vector<pair<int, int>> in;
    vector<char> l;

    void solveSudoku(vector<vector<char>>& board) {
        line = vector<set<char>>(9, set<char>());
        row  = vector<set<char>>(9, set<char>());
        grid = vector<set<char>>(9, set<char>());

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    in.push_back({i, j});
                } else {
                    line[i].insert(board[i][j]);
                    row[j].insert(board[i][j]);
                    grid[map_grid(i, j)].insert(board[i][j]);
                }
            }
        }
        dfs(0, board);
    }

    int map_grid(int i, int j) {
        return i / 3 + (j / 3) * 3;
    }

    void dfs(int i, vector<vector<char>>& board) {
        if (i == in.size()) {
            for (int k = 0; k < in.size(); k++) {
                board[in[k].first][in[k].second] = l[k];
            }
            return;
        }

        int x = in[i].first;
        int y = in[i].second;
        for (char c = '1'; c <= '9'; c++) {
            if (line[x].find(c) == line[x].end() && row[y].find(c) == row[y].end() && grid[map_grid(x, y)].find(c) == grid[map_grid(x, y)].end()) {
                l.push_back(c);
                line[x].insert(c);
                row[y].insert(c);
                grid[map_grid(x, y)].insert(c);
                dfs(i + 1, board);
                line[x].erase(c);
                row[y].erase(c);
                grid[map_grid(x, y)].erase(c);
                l.pop_back();
            }
        }
    }
};