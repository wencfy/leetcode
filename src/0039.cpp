/**
 * Combination Sum
 * 
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen numbers sum to target.
 * You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<int> nums;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        nums = candidates;
        recursive(target);
        return res;
    }

    void recursive(int target) {
        // cout << "nums: ";
        // for (auto i: nums) {
        //     cout << i << " ";
        // }
        // cout << "cur: ";
        // for (auto i: cur) {
        //     cout << i << " ";
        // }
        // cout << endl << "target: " << target << endl;

        if (target && !nums.empty()) {
            int curNum = nums.front();
            nums.erase(nums.begin());
            for (int i = 0; i * curNum <= target; i++) {
                // push
                for (int j = 0; j < i; j++) {
                    cur.push_back(curNum);
                }

                recursive(target - i * curNum);

                // back track
                for (int j = 0; j < i; j++) {
                    cur.pop_back();
                }
            }
            nums.emplace(nums.begin(), curNum);
        } else if (!target) {
            res.push_back(cur);
        }
    }
};

int main() {
    vector<int> nums = { 2, 3, 5 };
    vector<vector<int>> res = (new Solution()) ->combinationSum(nums, 8);

    for (auto line: res) {
        for (auto point: line) {
            cout << point << " ";
        }
        cout << endl;
    }
}