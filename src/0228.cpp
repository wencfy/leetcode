/**
 * Summary Ranges
 * 
 * You are given a sorted unique integer array nums.
 * 
 * A range [a,b] is the set of all integers from a to b (inclusive).
 * 
 * Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
 * 
 * Each range [a,b] in the list should be output as:
 *  "a->b" if a != b
 *  "a" if a == b
 */

#include "iostream"
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (!nums.size()) {
            return ret;
        }

        int start = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if ((long) nums[i] - nums[i - 1] == 1) {

            } else {
                if (start == nums[i - 1]) {
                    ret.push_back(to_string(start));
                } else {
                    ret.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }

        int i = nums.size();
        if (start == nums[i - 1]) {
            ret.push_back(to_string(start));
        } else {
            ret.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
        }
        return ret;
    }
};