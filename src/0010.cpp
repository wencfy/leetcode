#include "iostream"
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int m;
    int n;
    string s;
    string p;
public:
    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();
        this->s = s;
        this->p = p;
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return dfs(0, 0);
    }

    bool dfs(int i, int j) {
        if (i == m && j == n) {
            return true;
        } else if (j == n) {
            return false;
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        } else {
            bool ret = false;
            if (j + 1 < n && p[j + 1] == '*') {
                ret = ret || dfs(i, j + 2);
            }
            if (i < m && (p[j] == '.' || p[j] == s[i])) {
                if (j + 1 < n && p[j + 1] == '*') {
                    ret = ret || dfs(i + 1, j) || dfs(i + 1, j + 2);
                } else {
                    ret = ret || dfs(i + 1, j + 1);
                }
            }

            dp[i][j] = ret;
            return ret;
        }
    }
};