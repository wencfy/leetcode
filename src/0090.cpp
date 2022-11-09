/**
 * Subsets II
 * 
 * Given an integer array nums that may contain duplicates,
 * return all possible subsets (the power set).
 */

#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> mappedNums;
        for (int num: nums) {
            mappedNums[num]++;
        }
        return getSubsets(mappedNums);
    }

    vector<vector<int>> getSubsets(map<int, int> mappedNums) {
        vector<vector<int>> res;
        if (mappedNums.size() == 0) {
            res = { {} };
        } else if (mappedNums.size() == 1) {
            pair<int, int> numAndCount = *mappedNums.begin();
            for (int i = 0; i <= numAndCount.second; i++) {
                res.push_back(vector<int>(i, numAndCount.first));
            }
        } else {
            pair<int, int> numAndCount = *mappedNums.begin();
            mappedNums.erase(mappedNums.begin());
            vector<vector<int>> subsetsForRest = getSubsets(mappedNums);
            for (auto subset: subsetsForRest) {
                res.push_back(subset);
                for (int i = 1; i <= numAndCount.second; i++) {
                    auto curSubset = subset;
                    curSubset.insert(
                        curSubset.begin(),
                        i,
                        numAndCount.first
                    );
                    res.push_back(curSubset);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = { 1, 1, 2, 2 };
    vector<vector<int>> res = (new Solution()) ->subsetsWithDup(nums);
    for (auto line: res) {
        for (auto point: line) {
            cout << point << " ";
        }
        cout << endl;
    }
}