/**
 * Tallest Billboard
 * 
 * You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
 * 
 * You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
 * 
 * Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int s = 0;
        for (int rod: rods) {
            s += rod;
        }

        vector<int> dp(s + 1, -1);
        dp[0] = 0;

        for (int rod: rods) {
            vector<int> dpPrev(dp.begin(), dp.end());
            for (int i = 0; i <= s - rod; i++) {
                if (dpPrev[i] == -1) {
                    continue;
                } else {
                    dp[i + rod] = max(dp[i + rod], dpPrev[i] + rod);
                    dp[abs(i - rod)] = max(dp[abs(i - rod)], max(dpPrev[i], dpPrev[i] - i + rod));
                }
            }
        }

        // for (int d: dp) {
        //     cout << d << endl;
        // }

        return dp[0];
    }
};