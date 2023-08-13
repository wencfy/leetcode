/**
 * Check if There is a Valid Partition For The Array
 * 
 * You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.
 * 
 * We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:
 * 
 * The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
 * The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
 * The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
 * Return true if the array has at least one valid partition. Otherwise, return false.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp = vector<bool>(nums.size(), false);

        for (int i = nums.size() - 2; i >= 0; i--) {
            int j = 0;
            if (nums[i] == nums[i + 1]) {
                j = i + 1;
            }
            if (!j) {
            } else if (j == nums.size() - 1) {
                dp[i] = true;
            } else if (dp[j + 1]) {
                dp[i] = true;
            }
            
            j = 0;
            if (i + 2 < nums.size()) {
                if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
                    j = i + 2;
                } else if (nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1) {
                    j = i + 2;
                }
            }

            if (!j) {
            } else if (j == nums.size() - 1) {
                dp[i] = true;
            } else if (dp[j + 1]) {
                dp[i] = true;
            }

        }

        for (auto d: dp) {
            cout << d << " ";
        }
        cout << endl;

        return dp[0];
    }
};