#include "iostream"
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret;
        for (int i = 0; i < l.size(); i++) {
            vector<int> list = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(list.begin(), list.end());
            if (list.size() <= 2) {
                ret.push_back(true);
            } else {
                bool flag = true;
                for (int i = 2; i < list.size(); i++) {
                    if (list[i] - list[i - 1] == list[i - 1] - list[i - 2]) {
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                }
                ret.push_back(flag);
            }
        }
        return ret;
    }
};