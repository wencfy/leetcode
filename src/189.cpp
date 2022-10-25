/**
 * Given an array, rotate the array to the right by k steps,
 * where k is non-negative.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res(size);
        for (int i = 0; i < size; i++) {
            int index = (i + size - k % size) % size;
            res[i] = nums[index];
        }
        nums = res;
    }
};

int main() {
    vector<int> v = {1, 2};
    (new Solution()) ->rotate(v, 3);
}