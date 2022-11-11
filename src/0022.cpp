/**
 * Generate Parentheses
 * 
 * Given n pairs of parentheses,
 * write a function to generate all combinations of well-formed parentheses.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int leftCnt = 0;
    string cur = "";
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        if (n) {
            // push '('
            cur.push_back('(');
            leftCnt++;
            generateParenthesis(n - 1);
            leftCnt--;
            cur.pop_back();
        }

        if (leftCnt && n) {
            // push ')'
            cur.push_back(')');
            leftCnt--;
            generateParenthesis(n);
            leftCnt++;
            cur.pop_back();
        }

        if (leftCnt && !n) {
            for (int i = 0; i < leftCnt; i++) {
                cur.push_back(')');
            }
            res.push_back(cur);
            for (int i = 0; i < leftCnt; i++) {
                cur.pop_back();
            }
        }

        return res;
    }
};

int main() {
    int n = 8;
    vector<string> res = (new Solution()) ->generateParenthesis(n);
    for (string str: res) {
        cout << str << endl;
    }
}