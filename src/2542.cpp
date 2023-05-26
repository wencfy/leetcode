/**
 * Maximum Subsequence Score
 * 
 * You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
 * 
 * It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
 */

#include "iostream"
#include "algorithm"
#include "numeric"
#include "queue"
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> indices(nums1.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) -> bool {
            return nums2[a] > nums2[b];
        });

        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums1[indices[i]];
            q.push(nums1[indices[i]]);
        }
        long long score = sum * nums2[indices[k - 1]];

        for (int i = k; i < nums1.size(); i++) {
            if (q.top() < nums1[indices[i]]) {
                sum -= q.top();
                q.pop();
                q.push(nums1[indices[i]]);
                sum += nums1[indices[i]];
            }
            long long tmp = sum * nums2[indices[i]];
            if (tmp > score) {
                score = tmp;
            }
        }

        return score;
    }
};

int main() {
    vector<int> nums1 = {23,16,20,7,3};
    vector<int> nums2 = {19,21,22,22,12};
    cout << (new Solution()) ->maxScore(nums1, nums2, 3) << endl;
}