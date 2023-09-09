#include "iostream"
#include "string"
using namespace std;

class Solution {
    vector<vector<int>> dp;
    string s, p;
public:
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, -1));
        this->s = s;
        this->p = p;

        return dfs(0, 0);
    }

    int dfs(int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ret = 0;
        if (i == s.length()) {
            if (j == p.length()) {
                ret = 1;
            } else if (p[j] == '*') {
                ret = ret || dfs(i, j + 1);
            }
        } else if (s[i] == p[j] || p[j] == '?') {
            ret = ret || dfs(i + 1, j + 1);
        } else if (p[j] == '*') {
            ret = ret || dfs(i, j + 1) || dfs(i + 1, j);
        }
        dp[i][j] = ret;
        return ret;
    }
};