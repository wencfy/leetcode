#include "iostream"
#include "map"
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];

        map<int, int> mp;
        mp[prefix[0] % p] = 0;

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = (prefix[i - 1] + nums[i]) % p;
            mp[prefix[i] % p] = i;
        }

        int remainder = prefix[nums.size() - 1] % p;
        if (remainder == 0) {
            return 0;
        }

        int ret = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int r = prefix[i] % p;
            r = r > remainder ? r - remainder : r + p - remainder;
            ret = min(ret, i - mp[r]);
        }

        return ret;
    }
};