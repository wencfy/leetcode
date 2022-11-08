/**
 * Subsets
 * 
 * Given an integer array nums of unique elements,
 * return all possible subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets.
 * Return the solution in any order.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return { {} };
        }
        int front = nums.front();
        nums.erase(nums.begin());
        vector<vector<int>> subSets = subsets(nums);
        vector<vector<int>> res;
        for (vector<int> subSet: subSets) {
            res.push_back(subSet);
            subSet.emplace(subSet.begin(), front);
            res.push_back(subSet);
        }
        return res;
    }
};

int main() {
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> res = (new Solution()) ->subsets(nums);
    for (auto line: res) {
        for (auto point: line) {
            cout << point << " ";
        }
        cout << endl;
    }
}