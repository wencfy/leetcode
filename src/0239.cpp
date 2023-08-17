/**
 * Sliding Window Maximum
 * 
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * 
 * Return the max sliding window.
 */

#include "iostream"
#include "deque"
#include "vector"
using namespace std;

// TLE
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> dp = vector<int>(nums.begin(), nums.end());
//         for (int i = 1; i < k; i++) {
//             for (int j = 0; j + i < nums.size(); j++) {
//                 dp[j] = max(dp[j], nums[j + i]);
//             }
//         }
//         return vector<int>(dp.begin(), dp.end() - k + 1);
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ret.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            ret.push_back(nums[dq.front()]);
        }

        return ret;
    }
};