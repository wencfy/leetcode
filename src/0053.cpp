#include "iostream"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = nums[0];
        int maxS = s;
        for (int i = 1; i < nums.size(); i++) {
            s = max(s + nums[i], nums[i]);
            if (maxS < s) {
                maxS = s;
            }
        }
        return maxS;
    }
};