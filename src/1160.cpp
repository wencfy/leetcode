#include "iostream"
#include "map"
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> mp;
        for (char c: chars) {
            mp[c]++;
        }

        int ret = 0;

        for (string word: words) {
            map<char, int> m;
            for (char c: word) {
                m[c]++;
            }
            bool flag = true;
            for (auto p: m) {
                if (mp[p.first] < p.second) {
                    flag = false;
                    break;
                }
            }
            ret += flag * word.length();
        }
        return ret;
    }
};
