#include "iostream"
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;

        while (num2) {
            cnt += num2 & 1;
            num2 >>= 1;
        }

        int t = num1;
        while (t) {
            cnt -= t & 1;
            t >>= 1;
        }

        if (cnt > 0) {
            int ret = num1;
            int i = 1;
            while (cnt) {
                if (num1 & i) {
                    
                } else {
                    ret += i;
                    cnt--;
                }
                i <<= 1;
            }
            return ret;
        } else if (cnt < 0) {
            int ret = num1;
            int i = 1;
            while (cnt) {
                if (num1 & i) {
                    ret -= i;
                    cnt++;
                }
                i <<= 1;
            }
            return ret;
        } else {
            return num1;
        }
    }
};