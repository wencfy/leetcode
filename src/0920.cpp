/**
 * Number of Music Playlists
 * 
 * Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:
 * 
 * Every song is played at least once.
 * A song can only be played again only if k other songs have been played.
 * 
 * Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int moduler = 7 + 1e9;
        vector<vector<long>> dp = vector<vector<long>>(goal + 1, vector<long>(n + 1, 0));

        dp[0][0] = 1;

        for (int len = 1; len <= goal; len++) {
            for (int i = 1; i <= min(n, len); i++) {
                dp[len][i] = dp[len - 1][i - 1] * (n - i + 1) % moduler;
                if (i > k) {
                    dp[len][i] = (dp[len][i] + dp[len - 1][i] * (i - k)) % moduler;
                }
            }
        }

        return dp[goal][n];
    }
};