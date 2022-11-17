/**
 * Edit Distance
 * 
 * Given two strings word1 and word2,
 * return the minimum number of operations required to convert word1 to word2.
 * 
 * You have the following three operations permitted on a word:
 *  - Insert a character
 *  - Delete a character
 *  - Replace a character
 */

#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        for (auto line: dp) {
            for (auto point: line) {
                cout << point << " ";
            }
            cout << endl;
        }

        return dp[word1.length()][word2.length()];
    }
};

int main() {
    string word1 = "horse";
    string word2 = "ros";

    cout << (new Solution()) ->minDistance(word1, word2) << endl;
}