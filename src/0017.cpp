/**
 * Letter Combinations of a Phone Number
 * 
 * Given a string containing digits from 2-9 inclusive,
 * return all possible letter combinations that the number could represent.
 * Return the answer in any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is 
 * given below. Note that 1 does not map to any letters.
 */

#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<string>> letterMap = {
        {  },
        {  },
        { "a", "b", "c" },
        { "d", "e", "f" },
        { "g", "h", "i" },
        { "j", "k", "l" },
        { "m", "n", "o" },
        { "p", "q", "r", "s" },
        { "t", "u", "v" },
        { "w", "x", "y", "z" },
    };

    vector<string> res;
    string cur;

    vector<string> letterCombinations(string digits) {
        recursive(digits);
        return res;
    }

    void recursive(string digits) {
        if (!digits.empty()) {
            char front = digits.front();
            digits.erase(digits.begin());
            for (string mappedChar: letterMap[charToInt(front)]) {
                cur.append(mappedChar);
                recursive(digits);
                cur.pop_back();
            }
            digits.insert(digits.begin(), front);
        } else if (!cur.empty()) {
            res.push_back(cur);
        }
    }

    int charToInt(char c) {
        return c + 1 - '1';
    }
};

int main() {
    string digits = "23";
    vector<string> res = (new Solution()) ->letterCombinations(digits);
    for (string str: res) {
        cout << str << endl;
    }
}