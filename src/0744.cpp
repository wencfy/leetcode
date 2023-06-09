/**
 * Find Smallest Letter Greater Than Target
 * 
 * You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
 * 
 * Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
 */

#include "iostream"
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target >= letters[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low == letters.size() ? letters[0] : letters[low];
    }
};