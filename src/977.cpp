#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low  = getIndex(nums);
        int high = low + 1;
        int i    = 0;
        vector<int> res(nums.size());
        
        while (low >= 0 && high < nums.size()) {
            if (- nums[low] < nums[high]) {
                res[i++] = nums[low] * nums[low--];
            } else {
                res[i++] = nums[high] * nums[high++];
            }
        }
        while (low >= 0) {
            res[i++] = nums[low] * nums[low--];
        }
        while (high < nums.size()) {
            res[i++] = nums[high] * nums[high++];
        }
        return res;
    }

    /**
     * get index of the first number which is greater than 0
     */
    int getIndex(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == 0) {
                return mid;
            } else if (nums[mid] > 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};

int main() {
    vector<int> v = { -7, -3, 2, 3, 11 };
    vector<int> res = (new Solution())->sortedSquares(v);
    for (int i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}