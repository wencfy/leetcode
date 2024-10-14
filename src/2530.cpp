#include "iostream"
using namespace std;

class Solution {
public:
    class Compare {
        public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        }
    };
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;

        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i], i});
        }

        long long ret = 0;
        while (k--) {
            auto p = q.top();
            q.pop();
            ret += p.first;
            nums[p.second] = ceil(nums[p.second] * 1. / 3);
            q.push({nums[p.second], p.second});
        }
        return ret;
    }
};