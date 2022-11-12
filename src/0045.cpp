/**
 * Jump Game II
 * 
 * You are given a 0-indexed array of integers nums of length n.
 * You are initially positioned at nums[0].
 * 
 * Each element nums[i] represents the maximum length of a forward jump from index i.
 * In other words, if you are at nums[i],
 * you can jump to any nums[i + j] where:
 * 
 *  - 0 <= j <= nums[i] and
 *  - i + j < n
 * 
 * Return the minimum number of jumps to reach nums[n - 1].
 * The test cases are generated such that you can reach nums[n - 1].
 */

#include "iostream"
#include "vector"
using namespace std;

#define MAX_STEP 10001

class Solution {
public:
    vector<int> steps;

    int jump(vector<int>& nums) {
        steps.resize(nums.size(), 10001);
        steps[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                steps[i + j] = min(steps[i + j], steps[i] + 1);
            }
        }

        for (auto i: steps) {
            cout << i << " ";
        }
        cout << endl;

        return steps[nums.size() - 1];
    }
};

int main() {
    // vector<int> nums = { 2, 3, 1, 1, 4 };
    // vector<int> nums = { 2, 3, 0, 1, 4 };
    vector<int> nums(10000, 1000);
    (new Solution()) ->jump(nums);
}