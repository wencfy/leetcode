/**
 * Find All Anagrams in a String
 */

#include "iostream"
#include "string"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // const map of string p
        map<char, int> STR_MAP;
        for (char c: p) {
            STR_MAP[c]++;
        }

        vector<int> ret = {};

        // init
        map<char, int> letterCount;
        int length = p.length();
        for (int i = 0; i < length; i++) {
            letterCount[s[i]]++;
        }

        int start = 0;
        int end = length - 1;
        while (end < s.length()) {
            if (letterCount == STR_MAP) {
                ret.push_back(start);
            }
            // for (auto p: letterCount) {
            //     cout << p.first << " " << p.second << endl;
            // }
            // for (auto p: STR_MAP) {
            //     cout << p.first << " " << p.second << endl;
            // }
            
            char toBeDelete = s[start];
            letterCount[toBeDelete]--;
            if (letterCount[toBeDelete] == 0) {
                letterCount.erase(toBeDelete);
            }
            start++;
            end++;
            letterCount[s[end]]++;
        }

        return ret;
    }
};

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ret = (new Solution()) ->findAnagrams(s, p);
    for (int i: ret) {
        cout << i << " ";
    }
    cout << endl;
}