#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
    // divide and conquer
    // long long minimumSteps(string s) {
    //     long long l, r;
    //     return split(s, &l, &r);
    // }

    // easier approach
    long long minimumSteps(string s) {
        long long ret = 0;
        long long ones = 0;
        for (char c: s) {
            if (c == '1') {
                ones++;
            } else {
                ret += ones;
            }
        }
        return ret;
    }

    long long split(string s, long long *l, long long *r) {
        if (s.length() == 1) {
            if (s[0] == '0') {
                *l = 1;
                *r = 0;
            } else {
                *l = 0;
                *r = 1;
            }
            return 0;
        } else {
            int mid = s.length() / 2;
            string ls = s.substr(0, mid);
            string rs = s.substr(mid);

            long long ll, lr, rl, rr;
            long long ret = 0;
            ret += split(ls, &ll, &lr);
            ret += split(rs, &rl, &rr);
            ret += lr * rl;

            *l = ll + rl;
            *r = lr + rr;
            return ret;
        }
    }
};