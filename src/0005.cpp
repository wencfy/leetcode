/**
 * Longest Palindromic Substring
 * 
 * Given a string s, return the longest palindromic substring in s.
 */

#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<bool>> isPalindromic;
    int start = 0;
    int end = -1;

    string longestPalindrome(string s) {
        isPalindromic.resize(s.length(), vector<bool>(s.length(), false));

        for (int i = 0; i < s.length(); i++) {
            isPalindromic[i][i] = true;
            if (end - start < 0) {
                start = i;
                end = i;
            }
        }

        for (int i = 0; i + 1 < s.length(); i++) {
            if (s[i] == s[i + 1]) {
                isPalindromic[i][i + 1] = true;
                cout << start << " -- " << end << endl;
                if (end - start < 1) {
                    start = i;
                    end = i + 1;
                }
            }
        }

        for (int diff = 2; diff < s.length(); diff++) {
            for (int i = 0; i + diff < s.length(); i++) {
                if (s[i] == s[i + diff] && isPalindromic[i + 1][i + diff - 1]) {
                    isPalindromic[i][i + diff] = true;
                    if (end - start < diff) {
                        start = i;
                        end = i + diff;
                    }
                }
            }
        }

        // cout << start << " -- " << end << endl;
        return s.substr(start, end - start + 1);
    }
};

int main() {
    // string s = "babad";
    string s = "cbbd";
    cout << (new Solution()) ->longestPalindrome(s) << endl;
}