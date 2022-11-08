/**
 * 3 sum
 */

#include "set"
#include "map"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        nums = transformVector(nums);

        set<vector<int>> resSet;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int y = nums[j];
                int target = 0 - x - y;
                if (binarySearch(nums, j + 1, target)) {
                    resSet.insert({ x, y, target });
                }
            }
        }

        vector<vector<int>> res(resSet.size());
        copy(resSet.begin(), resSet.end(), res.begin());
        return res;
    }

    bool binarySearch(vector<int>& nums, int low, int target) {
        int high = nums.size() - 1;
        bool ret = false;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ret = true;
                break;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ret;
    }

    vector<int> transformVector(vector<int> &nums) {
        map<int, int> mp;
        vector<int> ret;
        for (int i: nums) {
            mp[i]++;
        }
        for (auto kv: mp) {
            if (kv.second > 3) {
                kv.second = 3;
            }
            for (int i = 0; i < kv.second; i++) {
                ret.push_back(kv.first);
            }
        }
        return ret;
    }
};

// utils
void printList(vector<vector<int>> res) {
    for (vector<int> v: res) {
        for (int i: v) {
            cout << i << ", ";
        }
        cout << endl;
    }
}

int main() {
    Solution *solution = new Solution();
    vector<int> nums(3000);
    printList(solution ->threeSum(nums));
}