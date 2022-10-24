#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beginIndex = 0;
        int endIndex   = nums.size() - 1;
        int midIndex;
        while (beginIndex < endIndex) {
            midIndex = (beginIndex + endIndex) / 2;
            if (nums[midIndex] == target) {
                return midIndex;
            } else if (nums[midIndex] < target) {
                beginIndex = midIndex + 1;
            } else {
                endIndex = midIndex;
            }
        }
        if (nums[beginIndex] == target) {
            return beginIndex;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution* solution = new Solution();

    // sample data
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
    cout << solution -> search(v, 2) << endl;
}