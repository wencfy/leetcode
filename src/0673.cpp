/**
 * Number of Longest Increasing Subsequence
 * 
 * Given an integer array nums,
 * return the number of longest increasing subsequences.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> longestSubsequence;
    vector<vector<pair<int, int>>> numsCount;

    int findNumberOfLIS(vector<int>& nums) {
        for (int num: nums) {
            if (longestSubsequence.empty()) {
                longestSubsequence.push_back(num);
                numsCount.push_back({ pair<int, int>(num, 1) });
            } else if (num > longestSubsequence.back()) {
                longestSubsequence.push_back(num);
                int count = getCountByTarget(numsCount.back(), num);
                numsCount.push_back({ pair<int, int>(num, count) });
            } else {
                int index = getIndexForUpdate(longestSubsequence, num);
                longestSubsequence[index] = num;
                if (index) {
                    int count = getCountByTarget(numsCount[index - 1], num);
                    numsCount[index].push_back(pair<int, int>(num, numsCount[index].back().second + count));
                } else {
                    numsCount[index].push_back(pair<int, int>(num, numsCount[index].back().second + 1));
                }
            }
        }

        return numsCount.back().back().second;
    }

    int getIndexForUpdate(const vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    int getCountByTarget(const vector<pair<int, int>>& numCount, int target) {
        int low = 0;
        int high = numCount.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (numCount[mid].first >= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if (high >= 0) {
            return numCount.back().second - numCount[high].second;
        } else {
            return numCount.back().second;
        }
    }
};

int main() {
    // vector<int> nums = { 1, 3, 5, 4, 7 };
    // vector<int> nums = { 1, 1, 1, 1, 1 };
    // vector<int> nums = { 1, 2, 4, 3, 5, 4, 7, 2 };
    vector<int> nums = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };
    cout << (new Solution()) ->findNumberOfLIS(nums) << endl;
}