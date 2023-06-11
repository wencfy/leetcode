/**
 * Maximum Value at a Given Index in a Bounded Array
 * 
 * You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
 * 
 * nums.length == n
 * nums[i] is a positive integer where 0 <= i < n.
 * abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
 * The sum of all the elements of nums does not exceed maxSum.
 * nums[index] is maximized.
 * 
 * Return nums[index] of the constructed array.
 * 
 * Note that abs(x) equals x if x >= 0, and -x otherwise.
 */

#include "iostream"
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        
        long long low = 0;
        long long high = maxSum;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (maxSum == findMin(n, index, mid)) {
                return mid + 1;
            } else if (maxSum > findMin(n, index, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high + 1;
    }

    long long findMin(long long n, long long index, long long val) {
        long long ret = 0;
        if (val >= index) {
            ret += (val + (val - index)) * (index + 1) / 2;
        } else {
            ret += val * (val + 1) / 2;
        }

        if (val >= n - 1 - index) {
            ret += (val + (val - n + 1 + index)) * (n - index) / 2;
        } else {
            ret += val * (val + 1) / 2;
        }

        ret -= val;
        return ret;
    }
};

int main() {
    cout << (new Solution())->maxValue(6, 2, 931384943) << endl;
}