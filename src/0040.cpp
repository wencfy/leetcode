/**
 * Combination Sum II
 * 
 * Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 */

#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    map<int, int> nums;
    vector<vector<int>> res;
    vector<int> cur;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (int num: candidates) {
            nums[num]++;
        }
        recursive(target);
        return res;
    }

    void recursive(int target) {
        if (target && !nums.empty()) {
            pair<int, int> numAndCount = *nums.begin();
            nums.erase(nums.begin());
            for (int i = 0; i <= numAndCount.second && i * numAndCount.first <= target; i++) {
                for (int j = 0; j < i; j++) {
                    cur.push_back(numAndCount.first);
                }

                recursive(target - i * numAndCount.first);

                for (int j = 0; j < i; j++) {
                    cur.pop_back();
                }
            }
            nums.insert(numAndCount);
        } else if (!target) {
            res.push_back(cur);
        }
    }
};

int main() {
    vector<int> nums = { 10, 1, 2, 7, 6, 1, 5 };
    vector<vector<int>> res = (new Solution()) ->combinationSum2(nums, 8);

    for (auto line: res) {
        for (auto point: line) {
            cout << point << " ";
        }
        cout << endl;
    }
}