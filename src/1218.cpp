/**
 * Longest Arithmetic Subsequence of Given Difference
 * 
 * Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
 * 
 * A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxEle = INT_MIN;
        int minEle = INT_MAX;
        for (int a: arr) {
            if (maxEle < a) {
                maxEle = a;
            }
            if (minEle > a) {
                minEle = a;
            }
        }
        vector<int> dp(maxEle - minEle + 1, 0);

        for (int a: arr) {
            if (a - difference < minEle) {
                dp[a - minEle] = 1;
            } else if (a - difference - minEle > maxEle - minEle) {
                dp[a - minEle] = 1;
            } else {
                dp[a - minEle] = 1 + dp[a - minEle - difference];
            }
        }

        int ret = 0;
        for (int d: dp) {
            if (ret < d) {
                ret = d;
            }
            // cout << d << " ";
        }
        return ret;
    }
};

int main() {
    vector<int> arr = {3,4,-3,-2,-4};
    cout << (new Solution())->longestSubsequence(arr, -5) << endl;
}
