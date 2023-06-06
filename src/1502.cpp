/**
 * Can Make Arithmetic Progression From Sequence
 * 
 * A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
 * 
 * Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
 */

#include "iostream"
#include "algorithm"
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != d) {
                return false;
            }
        }
        return true;
    }
};