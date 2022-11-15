/**
 * Longest Common Subsequence
 * 
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 * If there is no common subsequence, return 0.
 */

#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        for (auto line: dp) {
            for (auto point: line) {
                cout << point << " ";
            }
            cout << endl;
        }

        return dp[text1.length()][text2.length()];
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << (new Solution()) ->longestCommonSubsequence(text1, text2) << endl;
}