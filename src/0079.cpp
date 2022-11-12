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
#include "map"
using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    string word;
    int curPtr;
    bool res = false;

    bool exist(vector<vector<char>>& board, string word) {
        this ->board = board;
        this ->word = word;

        map<char, int> charsInBoard;
        for (auto line: board) {
            for (auto point: line) {
                charsInBoard[point]++;
            }
        }
        for (char c: word) {
            if (!charsInBoard[c]) {
                return false;
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (backTracking(i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool backTracking(int x, int y) {
        if (curPtr == word.length()) {
            return true;
        }
        if (!isValid(x, y)) {
            return false;
        }

        char temp = board[x][y];
        if (word[curPtr] == temp) {
            board[x][y] = '$';
            curPtr++;
            for (auto dir: dirs) {
                if (backTracking(x + dir[0], y + dir[1])) {
                    return true;
                }
            }
            board[x][y] = temp;
            curPtr--;
        }
        return false;
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
