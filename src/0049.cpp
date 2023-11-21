#include "iostream"
#include "string"
#include "map"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<map<char, int>> anagram_map;

        vector<vector<string>> ret;
        for (string s: strs) {
            map<char, int> mp;
            for (char c: s) {
                mp[c]++;
            }

            int flag = true;
            for (int i = 0; i < anagram_map.size(); i++) {
                if (anagram_map[i] == mp) {
                    ret[i].push_back(s);
                    flag = false;
                }
            }
            if (flag) {
                anagram_map.push_back(mp);
                ret.push_back(vector<string>());
                ret.back().push_back(s);
            }
        }
        return ret;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    (new Solution()) ->groupAnagrams(strs);
}