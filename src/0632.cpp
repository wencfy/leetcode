#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    class Compare {
        public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.first >= b.first) {
                return true;
            } else {
                return false;
            }
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;

        vector<int> idxs(n, 0);
        for (int i = 0; i < n; i++) {
            q.push({nums[i][idxs[i]++], i});
        }
        vector<pair<int, int>> all;

        int s = -1;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int i = p.second;
            if (idxs[i] == 1) {
                s = all.size();
            }
            all.push_back(p);
            if (idxs[i] != nums[i].size()) {
                q.push({nums[i][idxs[i]++], i});
            } else {
                continue;
            }
        }

        // for (auto p: all) {
        //     cout << p.first << " " << p.second << endl;
        // }

        // from -> cnt
        vector<int> cnt(n, 0);
        int i = 0;
        int j = 0;
        while (j <= s) {
            auto p = all[j];
            cnt[p.second]++;
            j++;
        }
        int retl = all[i].first;
        int retr = all[j - 1].first;
        int minRange = retr - retl;

        bool flag = true;
        while (i < j && flag) {
            int idx = -1;
            while (i < j) {
                auto p = all[i];
                cnt[p.second]--;
                i++;
                if (cnt[p.second] == 0) {
                    flag = false;
                    idx = p.second;
                    if (all[j - 1].first - p.first < minRange) {
                        retl = p.first;
                        retr = all[j - 1].first;
                        minRange = retr - retl;
                    }
                    break;
                }
            }
            while (j < all.size()) {
                auto p = all[j];
                cnt[p.second]++;
                j++;
                if (p.second == idx) {
                    flag = true;
                    break;
                }
            }
        }
        return {retl, retr};
    }
};