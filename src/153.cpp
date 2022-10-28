/**
 * Given the sorted rotated array nums of unique elements,
 * return the minimum element of this array.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ret;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid + 1 < nums.size() && nums[mid + 1] < nums[mid]) {
                return nums[mid + 1];
            } else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if (nums[mid] > nums[low] && nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[low] && nums[mid] < nums[high]) {
                high = mid - 1;
            } else {
                // initially sorted
                ret = nums[low];
                break;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = { 3, 4, 1, 2 };
    cout << (new Solution()) ->findMin(nums) << endl;
}