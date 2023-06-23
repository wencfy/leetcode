/**
 * Longest Arithmetic Subsequence
 * 
 * Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
 * 
 * Note that:
 *  A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 *  A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/

#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        vector<unordered_map<int, int>> dp(nums.size());

        int maxSize = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int cnt = 1;
                if (dp[j].count(diff)) {
                    cnt = dp[j][diff];
                }
                dp[i][diff] = cnt + 1;
                maxSize = max(maxSize, dp[i][diff]);
            }
        }

        return maxSize;
    }
};