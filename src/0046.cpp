/**
 * Permutations
 * 
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) {
            return {{nums[0]}};
        }

        int b = nums.back();
        nums.pop_back();
        auto subSet = permute(nums);
        vector<vector<int>> ret = vector<vector<int>>();
        for (auto sub: subSet) {
            for (int i = 0; i <= sub.size(); i++) {
                auto copy = vector<int>(sub);
                copy.insert(copy.begin() + i, b);
                ret.push_back(copy);
            }
        }
        return ret;
    }
};