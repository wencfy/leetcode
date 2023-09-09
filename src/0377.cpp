#include "iostream"
#include "vector"
using namespace std;

class Solution {
    vector<int> nums;
    vector<int> memo;
public:
    int combinationSum4(vector<int>& nums, int target) {
        this->nums = nums;
        this->memo = vector<int>(target + 1, -1);
        return dfs(target);
    }

    int dfs(int target) {
        if (target == 0) {
            return 1;
        }

        if (memo[target] != -1) {
            return memo[target];
        }

        int ret = 0;
        for (int num: nums) {
            if (target >= num) {
                ret += dfs(target - num);
            }
        }
        memo[target] = ret;
        return ret;
    }
};