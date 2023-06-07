/**
 * Minimum Flips to Make a OR b Equal to c
 * 
 * Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * 
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
 */

#include "iostream"
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int minF = 0;
        while (a || b || c) {
            if (c & 1) {
                if (a & 1 | b & 1) {

                } else {
                    minF += 1;
                }
            } else {
                minF += a & 1;
                minF += b & 1;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return minF;
    }
};