#include "iostream"
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> cap = vector<int>(height.size());
        int h = -1;
        for (int i = 0; i < height.size(); i++) {
            h = max(height[i], h);
            cap[i] = h;
        }
        h = -1;
        for (int i = height.size() - 1; i >= 0; i--) {
            h = max(height[i], h);
            cap[i] = min(cap[i], h);
        }

        int maxTrap = 0;
        for (int i = 0; i < height.size(); i++) {
            maxTrap += cap[i] - height[i];
        }
        return maxTrap;
    }
};