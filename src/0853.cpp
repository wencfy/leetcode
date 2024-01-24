#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> index = vector<int>(position.size());
        for (int i = 0; i < index.size(); i++) {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](auto a, auto b) {
            return position[a] < position[b];
        });

        vector<pair<int, double>> s;

        // {v, time}
        for (int i = 0; i < index.size(); i++) {
            int idx = index[i];
            int sp = speed[idx];
            int pos = position[idx];
            double t = 1. * (target - pos) / sp;

            while (!s.empty()) {
                auto p = s[s.size() - 1];
                if (sp < p.first && t >= p.second) {
                    s.pop_back();
                } else {
                    break;
                }
            }

            s.push_back({sp, t});
        }
        return s.size();
    }
};