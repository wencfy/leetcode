#include "iostream"
#include "queue"
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i], i});
        }

        vector<bool> vis(nums.size(), false);
        long long score = 0;

        while (!q.empty()) {
            auto top = q.top();
            q.pop();

            int idx = top.second;
            if (!vis[idx]) {
                vis[idx] = true;
                if (idx - 1 >= 0) {
                    vis[idx - 1] = true;
                }
                if (idx + 1 < nums.size()) {
                    vis[idx + 1] = true;
                }
                score += top.first;
            }
        }

        return score;
    }
};