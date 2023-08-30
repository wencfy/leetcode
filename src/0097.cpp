/**
 * Interleaving String
 * 
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
 * 
 * An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
 * 
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
 * 
 * Note: a + b is the concatenation of strings a and b.
*/

#include "iostream"
using namespace std;

class Solution {
    string s1;
    string s2;
    string s3;
    vector<vector<vector<int>>> dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->dp = vector<vector<vector<int>>>(s3.length(), vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -1)));

        return dfs(0, 0, 0);
    }

    bool dfs(int i, int j, int k) {
        if (i == s3.length()) {
            if (j == s1.length() && k == s2.length()) {
                return true;
            }
            return false;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        bool ret = false;
        if (s3[i] == s1[j]) {
            ret = ret || dfs(i + 1, j + 1, k);
        }

        if (s3[i] == s2[k]) {
            ret = ret || dfs(i + 1, j, k + 1);
        }

        dp[i][j][k] = ret;
        return ret;
    }
};