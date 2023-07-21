/**
 * Number of Longest Increasing Subsequence
 * 
 * _2 means 2nd time of dealing with this problem
 * 
 * Given an integer array nums, return the number of longest increasing subsequences.
 * Notice that the sequence has to be strictly increasing.
 */

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = 0;
                    }

                    if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(dp.begin(), dp.end());
        int ret = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == maxLength) {
                ret += count[i];
            }
        }
        return ret;
    }
};