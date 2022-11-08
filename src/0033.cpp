/**
 * Search in Rotated Sorted Array
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int split = findSplit(nums);
        int ret;
        if (target >= nums[0]) {
            ret = binarySearch(nums, target, 0, split);
        } else if (target <= nums.back()) {
            ret = binarySearch(nums, target, split + 1, nums.size() - 1);
        } else {
            ret = -1;
        }
        return ret;
    }

    int findSplit(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[low] && nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[low] && nums[mid] < nums[high]) {
                high = mid - 1;
            } else {
                return high;
            }
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int target, int start, int end) {
        int low = start;
        int high = end;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> v = { 4 };
    cout << (new Solution()) ->search(v, 3) << endl;
}