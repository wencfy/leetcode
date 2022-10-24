#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // miss
        return high + 1;
    }
};

int main() {
    vector<int> v = {1, 3, 5, 6};
    cout << (new Solution())->searchInsert(v, 6) << endl;
    return 0;
}