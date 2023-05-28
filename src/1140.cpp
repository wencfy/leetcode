/**
 * Stone Game II
 * 
 * Alice and Bob continue their games with piles of stones.
 * There are a number of piles arranged in a row, and each pile
 *  has a positive integer number of stones piles[i].
 * The objective of the game is to end with the most stones.
 * 
 * Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
 * 
 * On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
private:
    vector<int> sumPiles;

public:
    // int stoneGameII(vector<int>& piles) {
    //     // init
    //     this ->sumPiles = piles;
    //     for (int i = piles.size() - 2; i >= 0; i--) {
    //         sumPiles[i] += sumPiles[i + 1];
    //     }

    //     return opt(0, 1);
    // }

    // int opt(int start, int m) {
    //     if (sumPiles.size() - start <= 2 * m) {
    //         return sumPiles[start];
    //     } else {
    //         int maxCnt = -1;
    //         for (int i = 1; i <= 2 * m; i++) {
    //             int count = sumPiles[start] - opt(start + i, max(i, m));
    //             if (maxCnt < count) {
    //                 maxCnt = count;
    //             }
    //         }
    //         return maxCnt;
    //     }
    // }

    int stoneGameII(vector<int>& piles) {
        // init
        this ->sumPiles = piles;
        for (int i = piles.size() - 2; i >= 0; i--) {
            sumPiles[i] += sumPiles[i + 1];
        }
        vector<vector<int>> dp(101, vector<int>(101, 0));

        for (int s = piles.size() - 1; s >= 0; s--) {
            for (int m = 1; m <= piles.size(); m++) {
                if (piles.size() - s <= 2 * m) {
                    dp[s][m] = sumPiles[s];
                } else {
                    int maxCnt = -1;
                    for (int i = 1; i <= 2 * m; i++) {
                        int count = sumPiles[s] - dp[s + i][max(m, i)];
                        if (maxCnt < count) {
                            maxCnt = count;
                        }
                    }
                    dp[s][m] = maxCnt;
                }
            }
        }
        
        return dp[0][1];
    }
};

int main() {
    vector<int> piles = {1};
    cout << (new Solution())->stoneGameII(piles) << endl;
}

