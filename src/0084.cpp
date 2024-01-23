#include "iostream"
using namespace std;
#include "vector"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> s;
        heights.push_back(0);

        int m = 0;
        for (int h: heights) {
            if (s.empty()) {
                s.push_back({h, 0});
            } else {

                for (auto iter = s.begin(); iter != s.end(); iter++) {
                    (*iter).second++;
                }
                
                int w = 0;
                while (s.size() && s.back().first >= h) {
                    auto p = s.back();
                    s.pop_back();
                    w = max(w, p.second);
                    m = max(m, p.first * p.second);
                }
                s.push_back({h, w});
            }
        }
        return m;
    }
};