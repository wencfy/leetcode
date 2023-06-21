/**
 * Minimum Cost to Make Array Equal
 * 
 * You are given two 0-indexed arrays nums and cost consisting each of n positive integers.
 * 
 * You can do the following operation any number of times:
 * 
 * Increase or decrease any element of the array nums by 1.
 * 
 * The cost of doing one operation on the ith element is cost[i].
 * 
 * Return the minimum total cost such that all the elements of the array nums become equal.
 */

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost, int mid) {
        long long curC = 0;
        for (int i = 0; i < nums.size(); i++) {
            curC += abs((long long) nums[i] - mid) * cost[i];
        }
        return curC;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left = nums.front();
        int right = nums.front();

        for (int num: nums) {
            if (left > num) {
                left = num;
            }
            if (right < num) {
                right = num;
            }
        }

        long long ret = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long cost1 = minCost(nums, cost, mid);
            long long cost2 = minCost(nums, cost, mid + 1);

            if (cost1 < cost2) {
                right = mid;
                ret = cost1;
            } else if (cost1 > cost2) {
                left = mid + 1;
                ret = cost2;
            } else {
                return cost1;
            }
        }
        return ret;
    }
};