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
    bool canJump(vector<int>& nums) {
        int neededSteps = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= neededSteps) {
                neededSteps = 0;
            }
            neededSteps++;
        }
        return neededSteps == 1;
    }
};

int main() {
    vector<int> nums = { 3, 2, 1, 0, 4 };
    // vector<int> nums = { 2, 3, 1, 1, 4 };
    cout << (new Solution()) ->canJump(nums) << endl;
}