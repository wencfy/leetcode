/**
 * Minimum Size Subarray Sum
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start    = 0;
        int end      = 0;
        int cur      = nums[start];
        int minCount = 0;
        while (start < nums.size() && end < nums.size()) {
            if (cur < target) {
                end++;
                if (end < nums.size()) {
                    cur += nums[end];
                }
            } else {
                int count = end - start + 1;
                if (minCount == 0) {
                    minCount = count;
                } else if (minCount > count) {
                    minCount = count;
                }
                cur -= nums[start];
                start++;
            }
        }
        return minCount;
    }
};

int main() {
    // int target = 7;
    // vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    // int target = 0;
    // vector<int> nums = { 1, 1, 1 };
    int target = 11;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    cout << (new Solution()) ->minSubArrayLen(target, nums) << endl;
}