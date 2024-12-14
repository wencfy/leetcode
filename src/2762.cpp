#include "iostream"
#include "map"
#include "set"
using namespace std;

class Solution {
public:
    // TLE
    // long long continuousSubarrays(vector<int>& nums) {
    //     long long total = 0;
    //     vector<pair<int, int>> minmax(nums.size());
    //     for (int dis = 0; dis < nums.size(); dis++) {
    //         for (int i = 0; i + dis < nums.size(); i++) {
    //             if (dis == 0) {
    //                 minmax[i] = {nums[i], nums[i]};
    //                 total++;
    //             } else {
    //                 minmax[i].first = min(minmax[i].first, nums[i + dis]);
    //                 minmax[i].second = max(minmax[i].second, nums[i + dis]);
    //                 if (minmax[i].second - minmax[i].first > 2) {
    //                     continue;
    //                 } else {
    //                     total++;
    //                 }
    //             }
    //         }
    //     }
    //     return total;
    // }

    // sliding window
    long long continuousSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long total = 0;

        int start = 0, end = 0;
        while (end < nums.size()) {
            if (mp.find(nums[end]) == mp.end()) {
                mp[nums[end]] = 1;
            } else {
                mp[nums[end]]++;
            }

            set<int> to_delete;
            for (auto p: mp) {
                if (abs(nums[end] - p.first) > 2) {
                    to_delete.insert(p.first);
                }
            }

            while (!to_delete.empty()) {
                mp[nums[start]]--;
                if (mp[nums[start]] == 0) {
                    mp.erase(nums[start]);
                    to_delete.erase(nums[start]);
                }
                start++;
            }

            total += end - start + 1;
            end++;
        }

        return total;
    }
};