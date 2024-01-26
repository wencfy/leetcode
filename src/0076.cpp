// Minimum Window Substring
#include "iostream"
#include "map"
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;
        for (char c: t) {
            tmp[c]++;
        }

        int i = 0;
        int j = 0;
        string ret = "";
        while (j < s.length()) {
            smp[s[j]]++;
            while (i < s.length() && smp[s[i]] > tmp[s[i]]) {
                smp[s[i]]--;
                i++;
            }

            bool flag = true;
            for (auto p: tmp) {
                if (smp[p.first] < p.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (ret == "") {
                    ret = s.substr(i, j - i + 1);
                } else if (j - i + 1 < ret.length()) {
                    ret = s.substr(i, j - i + 1);
                }
            }
            j++;
        }
        return ret;
    }
};