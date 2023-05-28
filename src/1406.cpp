/**
 * Stone Game III
 * 
 * Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
 * 
 * Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.
 * 
 * The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.
 * 
 * The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.
 * 
 * Assume Alice and Bob play optimally.
 * 
 * Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.
 */

#include "iostream"
#include "string"
#include "vector"
#include "limits.h"
using namespace std;

class Solution {
private:
    vector<int> sumPiles;

public:
    string stoneGameIII(vector<int>& stoneValue) {
        this->sumPiles = stoneValue;
        for (int i = sumPiles.size() - 2; i >= 0; i--) {
            sumPiles[i] += sumPiles[i + 1];
        }

        vector<int> dp(sumPiles.size() + 1, 0);
        dp[sumPiles.size()] = 0;
        dp[sumPiles.size() - 1] = sumPiles[sumPiles.size() - 1];

        for (int i = sumPiles.size() - 2; i >= 0; i--) {
            int maxCnt = INT_MIN;
            for (int take = 1; take <= 3 && i + take <= sumPiles.size(); take++) {
                int count = sumPiles[i] - dp[i + take];
                if (maxCnt < count) {
                    maxCnt = count;
                }
            }
            dp[i] = maxCnt;
        }

        // int a = opt(0);
        // int b = sumPiles[0] - a;
        int a = dp[0];
        int b = sumPiles[0] - a;
        if (a > b) {
            return "Alice";
        } else if (a < b) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

    // int opt(int start) {
    //     if (start == sumPiles.size()) {
    //         return 0;
    //     } else if (start == sumPiles.size() - 1) {
    //         return sumPiles[start];
    //     } else {
    //         int maxCnt = INT_MIN;
    //         for (int i = 1; i <= 3 && start + i <= sumPiles.size(); i++) {
    //             int count = sumPiles[start] - opt(start + i);
    //             if (maxCnt < count) {
    //                 maxCnt = count;
    //             }
    //         }
    //         return maxCnt;
    //     }
    // }
};

int main() {
    vector<int> values = {1,2,3,7};
    cout << (new Solution()) ->stoneGameIII(values) << endl;
}