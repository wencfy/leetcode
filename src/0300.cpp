/**
 * Longest Increasing Subsequence
 * 
 * Given an integer array nums,
 * return the length of the longest strictly increasing subsequence.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longestSubsequence;

        for (int num: nums) {
            if (longestSubsequence.empty() || num > longestSubsequence.back()) {
                longestSubsequence.push_back(num);
            } else {
                // binary search
                int low = 0;
                int high = longestSubsequence.size() - 1;
                bool flag = true;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (num == longestSubsequence[mid]) {
                        flag = false;
                        break;
                    } else if (num > longestSubsequence[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                // for (int num: longestSubsequence) {
                //     cout << num << " ";
                // }
                // cout << endl;
                
                if (flag) {
                    longestSubsequence[low] = num;
                }
            }
        }

        return longestSubsequence.size();
    }
};

int main() {
    // vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector<int> nums = { 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12 };
    cout << (new Solution()) ->lengthOfLIS(nums) << endl;
}