/**
 * Permutations II
 * 
 * Given a collection of numbers, nums, that might contain duplicates,
 * return all possible unique permutations in any order.
 */

#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    map<int, int> numsMap;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int num: nums) {
            numsMap[num]++;
        }
        backTracking();
        return res;
    }

    void backTracking() {
        bool flag = true;
        for (auto it = numsMap.begin(); it != numsMap.end(); it++) {
            if (it ->second) {
                // if will do cur.push_back then should not push res
                flag = false;

                cur.push_back(it ->first);
                it ->second--;
                backTracking();

                // back tracking
                cur.pop_back();
                it ->second++;
            }
        }
        if (flag) {
            res.push_back(cur);
        }
    }
};

int main() {
    vector<int> nums = { 1, 1, 2, 2 };
    for (auto line: (new Solution()) ->permuteUnique(nums)) {
        for (auto point: line) {
            cout << point << " ";
        }
        cout << endl;
    }
}