/**
 * K Radius Subarray Averages
 * 
 * You are given a 0-indexed array nums of n integers, and an integer k.
 * 
 * The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.
 * 
 * Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.
 * 
 * The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.
 * 
 * For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.
 */

#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(), 0);

        if (2 * k >= nums.size()) {
            res = vector<int>(nums.size(), -1);
            return res;
        }

        long long s = 0;
        int i = 0;
        for (; i < k; i++) {
            res[i] = -1;
            s += nums[i];
        }

        for (int j = 0; j <= k; j++) {
            s += nums[i + j];
        }

        for (; i < nums.size() - k - 1; i++) {
            res[i] = s / (k * 2 + 1);
            if (i + k + 1 < nums.size()) {
                s = s - nums[i - k] + nums[i + k + 1];
            }
        }

        for (; i < nums.size(); i++) {
            res[i] = -1;
        }

        return res;
    }
};