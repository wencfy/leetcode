/**
 * House Robber II
 * 
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed.
 * All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one.
 * Meanwhile, adjacent houses have a security system connected,
 * and it will automatically contact the police if two adjacent houses were
 * broken into on the same night.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> nums;

    int rob(vector<int>& nums) {
        this ->nums = nums;

        if (nums.size() == 1) {
            return nums[0];
        }
        return max(getMax(0, nums.size() - 2), getMax(1, nums.size() - 1));
    }

    int getMax(int start, int end) {
        if (start == end) {
            return nums[start];
        } else {
            // max amount without robbing the previous house
            int withoutRobPre = 0;
            // max amount with robbing the previous house
            int robPre = 0;
            // max current robbing amount, = max(withoutRobPre + nums[i], robPre)
            int robAmount = 0;
            for (int i = start; i <= end; i++) {
                robAmount = max(withoutRobPre + nums[i], robPre);
                withoutRobPre = robPre;
                robPre = robAmount;
            }
            return robAmount;
        }
    }
};

int main() {
    vector<int> nums = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
    // vector<int> nums = { 2, 3, 2 };
    cout << (new Solution()) ->rob(nums) << endl;
}