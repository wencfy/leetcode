#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long cur = LLONG_MAX;
        long long count = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (cur >= nums[i]) {
                cur = nums[i];
            } else {
                long long eleCount = (nums[i] - 1) / cur;
                count += eleCount;
                cur = nums[i] / (eleCount + 1);
            }
        }
        return count;
    }
};