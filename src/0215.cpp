/**
 * Kth Largest Element in an Array
 * 
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Can you solve it without sorting?
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        int tarIdx = nums.size() - k;
        while (start < end) {
            int p = split(nums, start, end);
            if (p < tarIdx) {
                start = p + 1;
            } else if (p > tarIdx) {
                end = p - 1;
            } else {
                return nums[p];
            }
        }
        return nums[start];
    }

    int split(vector<int>& nums, int start, int end) {
        int front = start;
        int p = nums[start++];
        while (start <= end) {
            while (start < nums.size() && nums[start] <= p && start <= end) {
                start++;
            }
            while (end >= 0 && nums[end] >= p && start <= end) {
                end--;
            }
            
            if (start < end) {
                int temp = nums[start];
                nums[start++] = nums[end];
                nums[end--] = temp;
            }
        }

        nums[front] = nums[end];
        nums[end] = p;

        return end;
    }
};

int main() {
    vector<int> nums = {1, 1};
    cout << (new Solution())->findKthLargest(nums, 2) << endl;
}