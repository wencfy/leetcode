/**
 * Minimum ASCII Delete Sum for Two Strings
 * 
 * Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
 */

#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector dp = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1));

        for (int i = s1.length() - 1; i >= 0; i--) {
            dp[i][s2.length()] = dp[i + 1][s2.length()] + s1[i];
        }

        for (int i = s2.length() - 1; i >= 0; i--) {
            dp[s1.length()][i] = dp[s1.length()][i + 1] + s2[i];
        }

        for (int i = s1.length() - 1; i >= 0; i--) {
            for (int j = s2.length() - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
                }
            }
        }

        return dp[0][0];
    }
};