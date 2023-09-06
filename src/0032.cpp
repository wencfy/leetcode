#include "iostream"
#include "vector"
#include "stack"
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> vec = vector<bool>(s.length(), false);
        stack<int> st = stack<int>();

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    vec[st.top()] = true;
                    vec[i] = true;
                    st.pop();
                }
            }
        }

        int maxLen = 0;
        int len = 0;
        for (bool v: vec) {
            if (v) {
                len++;
            } else {
                maxLen = max(maxLen, len);
                len = 0;
            }
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
};