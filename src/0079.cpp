/**
 * Word Search
 * 
 * Given an m x n grid of characters board and a string word,
 * return true if word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    vector<vector<bool>> isVisited;
    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    string word;
    int curPtr;
    bool res = false;

    bool exist(vector<vector<char>>& board, string word) {
        this ->board = board;
        this ->word = word;
        this ->isVisited.resize(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size() && !res; i++) {
            for (int j = 0; j < board[i].size() && !res; j++) {
                backTracking(i, j);
            }
        }

        return res;
    }

    void backTracking(int x, int y) {
        if (isValid(x, y) && !isVisited[x][y] && word[curPtr] == board[x][y] && !res) {
            isVisited[x][y] = true;
            curPtr++;
            if (curPtr == word.length()) {
                res = true;
            } else {
                for (auto dir: dirs) {
                    backTracking(x + dir[0], y + dir[1]);
                }
            }
            isVisited[x][y] = false;
            curPtr--;
        }
    }

    bool isValid(int x, int y) {
        return x >= 0
            && y >= 0
            && x < board.size()
            && y < board[0].size();
    }
};

int main() {
    vector<vector<char>> board = {
        { 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A' },
        { 'A', 'A', 'A', 'A', 'A', 'A' },
    };
    cout << (new Solution()) ->exist(board, "AAAAAAAAAAAAAAB") << endl;
}
