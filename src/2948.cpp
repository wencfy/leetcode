#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums.size());
        vector<int> idx(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sorted[i] = nums[i];
            idx[i] = i;
        }
        sort(sorted.begin(), sorted.end());
        sort(idx.begin(), idx.end(), [&](auto a, auto b) {
            return nums[a] < nums[b];
        });

        int c = 0;
        vector<int> heads = {0};
        vector<int> groups(nums.size());
        groups[0] = 0;
        for (int i = 1; i < sorted.size(); i++) {
            if (sorted[i] - sorted[i - 1] > limit) {
                heads.push_back(i);
                c++;
            }
            groups[idx[i]] = c;
        }

        vector<int> ret(nums.size());

        for (int i = 0; i < ret.size(); i++) {
            int g = groups[i];

            ret[i] = sorted[heads[g]];
            heads[g]++;
        }

        return ret;
    }
};