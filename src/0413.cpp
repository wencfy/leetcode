/**
 * Arithmetic Slices
 * 
 * An integer array is called arithmetic if it consists of at least three 
 * elements and if the difference between any two consecutive elements is the same.
 * 
 * A subarray is a contiguous subsequence of the array.
 */

#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int index = 0;
        int res = 0;
        while (index + 2 < nums.size()) {
            int cursor = index + 1;
            int diff = nums[index + 1] - nums[index];
            while (cursor + 1 < nums.size() && nums[cursor + 1] - nums[cursor] == diff) {
                cursor++;
            }
            res += (cursor - index) * (cursor - index - 1) / 2;
            index = cursor;
        }
        return res;
    }
};

int main() {
    // vector<int> nums = { 1, 2, 3, 4 };
    vector<int> nums = { 1, 2, 3, 5, 7 };
    cout << (new Solution()) ->numberOfArithmeticSlices(nums) << endl;
}