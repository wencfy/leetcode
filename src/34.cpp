#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return getRange(nums, mid);
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return { -1, -1 };
    }

    vector<int> getRange(vector<int>& nums, int index) {
        int high = index;
        int low = index;
        int target = nums[index];
        while (low >= 0) {
            if (nums[low] == target) {
                low--;
            } else {
                break;
            }
        }
        while (high < nums.size()) {
            if (nums[high] == target) {
                high++;
            } else {
                break;
            }
        }
        return { low + 1, high - 1 };
    }
};

int main() {
    vector<int> v = { 5, 7, 7, 8, 8, 10 };
    vector<int> res = (new Solution()) ->searchRange(v, 8);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}