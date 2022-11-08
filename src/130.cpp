/**
 * Surrounded Regions
 * 
 * Given an m x n matrix board containing 'X' and 'O',
 * capture all regions that are 4-directionally surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> isVisited;
    vector<vector<char>> board;

    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }};

    void init(vector<vector<char>>& board) {
        isVisited = vector<vector<int>>(board.size(), vector<int>(board[0].size()));
        copy(board.begin(), board.end(), back_inserter(this ->board));
        return ;
    }

    void solve(vector<vector<char>>& board) {
        init(board);

        for (int i = 0; i < board.size(); i++) {
            dfs(i, 0);
            dfs(i, board[i].size() - 1);
            if (i == 0 || i == board.size() - 1) {
                for (int j = 0; j < board[i].size() - 1; j++) {
                    dfs(i, j);
                }
            }
        }

        // for (auto line: isVisited) {
        //     for (auto point: line) {
        //         cout << point << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!isVisited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    // deep first search
    void dfs(int x, int y) {
        if (!isValid(x, y)) {
            return ;
        }
        if (board[x][y] != 'O') {
            return ;
        }
        if (isVisited[x][y]) {
            return ;
        }
        isVisited[x][y] = true;
        for (vector<int> dir: dirs) {
            dfs(x + dir[0], y + dir[1]);
        }
        return ;
    }

    // judge if (x, y) is valid grid
    bool isValid(int x, int y) {
        return x >= 0
            && y >= 0
            && x < board.size()
            && y < board[0].size();
    }
};

int main() {
    vector<vector<char>> board = {
        { 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'O', 'X' },
        { 'X', 'X', 'O', 'X' },
        { 'X', 'O', 'X', 'X' },
    };

    (new Solution()) ->solve(board);

    for (auto line: board) {
        for (auto point: line) {
            cout << point << " ";
        }
        cout << endl;
    }
}