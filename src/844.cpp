/**
 * Backspace String Compare
 */

#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return parseString(s) == parseString(t);
    }

    string parseString(string withBackSpace) {
        string ret = "";
        for (int i = 0; i < withBackSpace.length(); i++) {
            char cur = withBackSpace[i];
            if (cur != '#') {
                ret.push_back(cur);
            } else {
                // allege it is not empty
                if (ret.length()) {
                    ret.pop_back();
                }
            }
        }
        return ret;
    }
};

int main() {
    string s = "ab###c";
    string t = "ad##c";
    cout << (new Solution()) ->backspaceCompare(s, t) << endl;
}