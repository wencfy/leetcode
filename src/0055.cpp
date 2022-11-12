/**
 * Jump Game
 * 
 * You are given an integer array nums.
 * You are initially positioned at the array's first index,
 * and each element in the array represents your maximum jump length at that position.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<bool> reachTable;

    bool canJump(vector<int>& nums) {
        reachTable.resize(nums.size());
        reachTable[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            if (reachTable[i]) {
                for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                    reachTable[i + j] = true;
                }
            }
        }

        // for (auto i: reachTable) {
        //     cout << i << " ";
        // }
        // cout << endl;

        return reachTable[nums.size() - 1];
    }
};

int main() {
    // vector<int> nums = { 3, 2, 1, 0, 4 };
    vector<int> nums = { 2, 3, 1, 1, 4 };
    cout << (new Solution()) ->canJump(nums) << endl;
}