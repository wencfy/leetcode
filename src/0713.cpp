/**
 * Subarray Product Less Than K,
 * Given an array of integers nums and an integer k, 
 * return the number of contiguous subarrays where the product 
 * of all the elements in the subarray is strictly less than k.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<int> resArr(nums.size());
        int product = 1;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            while (product >= k && j <= i) {
                product /= nums[j];
                j++;
            }
            resArr[i] = j;
        }
        
        int sum = 0;
        for (int num: resArr) {
            sum += num;
        }
        return (1 + nums.size()) * nums.size() / 2 - sum;
    }
};

int main() {
    vector<int> nums = { 10, 5, 2, 6 };
    cout << (new Solution()) ->numSubarrayProductLessThanK(nums, 100) << endl;
}