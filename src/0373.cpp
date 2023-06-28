/**
 * Find K Pairs with Smallest Sums
 * 
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 * 
 * Define a pair (u, v) which consists of one element from the first array and one element from the second array.
 * 
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
 */

#include "iostream"
#include "vector"
#include "queue"
#include "map"
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        map<pair<int, int>, bool> visited;
        visited[{0, 0}] = true;

        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            ret.push_back({nums1[i], nums2[j]});
            
            if (i + 1 < nums1.size() && !visited[{i + 1, j}]) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited[{i + 1, j}] = true;
            }

            if (j + 1 < nums2.size() && !visited[{i, j + 1}]) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited[{i, j + 1}] = true;
            }
        }

        return ret;
    }
};