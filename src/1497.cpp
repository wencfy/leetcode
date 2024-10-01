#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;
        for (int a: arr) {
            int key = a % k;
            if (key < 0) {
                key += k;
            }
            if (mp.find(key) == mp.end()) {
                mp[key] = 1;
            } else {
                mp[key]++;
            }
        }

        for (auto entry: mp) {
            int key = entry.first;
            int val = entry.second;

            if (key != 0) {
                if (mp.find(k - key) == mp.end()) {
                    return false;
                }
                int pairVal = mp[k - key];
                if (pairVal != val) {
                    return false;
                }
            } else {
                if (val % 2) {
                    return false;
                }
            }
        }
        return true;
    }
};