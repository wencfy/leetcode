/**
 * Delete Operation for Two Strings
 * 
 * Given two strings word1 and word2, return the minimum number of steps
 * required to make word1 and word2 the same.
 */

#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        dp.resize(word1.length() + 1, vector<int>(word2.length() + 1, 0));

        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
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

        return word1.length() + word2.length() - 2 * dp[word1.length()][word2.length()];
    }
};

int main() {
    string word1 = "sea";
    string word2 = "eat";
    cout << (new Solution()) ->minDistance(word1, word2) << endl;
}