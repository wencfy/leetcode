/**
 * Decode Ways
 * 
 * Given a string s containing only digits,
 * return the number of ways to decode it.
 */

#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    vector<int> count;

    int numDecodings(string s) {
        count.resize(s.size(), 0);

        if (s[0] != '0') {
            count[0] = 1;
        }

        int i = 1;
        if (s.length() > 1) {
            if (s[i] == '0') {
                count[i] = isLetter(s[i - 1], s[i]);
            } else {
                count[i] = count[i - 1] + isLetter(s[i - 1], s[i]);
            }
        }

        for (i = 2; i < s.length(); i++) {
            if (s[i] == '0') {
                count[i] = isLetter(s[i - 1], s[i]) * count[i - 2];
            } else {
                count[i] = count[i - 1] + isLetter(s[i - 1], s[i]) * count[i - 2];
            }
        }

        return count[s.length() - 1];
    }

    bool isLetter(char c1, char c2) {
        return c1 == '1' || (c1 == '2' && c2 <= '6');
    }
};

int main() {
    string s = "11106";
    cout << (new Solution()) ->numDecodings(s) << endl;
}