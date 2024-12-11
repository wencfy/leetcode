#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> count_before_prefix(200002, 0);

        for (int num: nums) {
            count_before_prefix[max(0, num - k)] += 1;
            count_before_prefix[num + k + 1] -= 1;
        }

        int max_count = 0;
        for (int i = 1; i < count_before_prefix.size(); i++) {
            count_before_prefix[i] += count_before_prefix[i - 1];
            max_count = max(count_before_prefix[i], max_count);
        }

        return max_count;
    }
};