/**
 * Given a 0-indexed integer array nums, find a peak element, and return its index.
 * If the array contains multiple peaks, return the index to any of the peaks.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ret;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPeak(nums, mid)) {
                ret = mid;
                break;
            } else if (nums[mid] < nums[low]) {
                high = mid - 1;
            } else if (nums[mid] < nums[high]) {
                low = mid + 1;
            } else {
                // mid is not peak
                // mid > low && mid > high
                if (nums[mid] < nums[mid - 1]) {
                    high = mid - 1;
                } else if (nums[mid] < nums[mid + 1]) {
                    low = mid + 1;
                }
            }
        }
        return ret;
    }

    bool isPeak(vector<int>& nums, int index) {
        bool ret;
        if (index == 0 && index == nums.size() - 1) {
            // only 1 element in the vector
            return true;
        } else if (index == 0) {
            // the start of the nums is peak
            ret = nums[index] > nums[index + 1];
        } else if (index == nums.size() - 1) {
            // the end of the nums is peak
            ret = nums[index] > nums[index - 1];
        } else {
            // greater than index - 1 && greater than index + 1
            ret = (nums[index] > nums[index + 1]) && (nums[index] > nums[index - 1]);
        }
        return ret;
    }
};

int main() {
    // vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };
    vector<int> nums = { 1 };
    cout << (new Solution()) ->findPeakElement(nums) << endl;
}
