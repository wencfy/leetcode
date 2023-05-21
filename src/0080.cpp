#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prevNum = nums[0];
        int prevCnt = 0;
        int cnt = 0;

        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == prevNum) {
                prevCnt++;
                if (prevCnt <= 2) {
                    nums[j++] = nums[i];
                    cnt++;
                }
            } else {
                prevNum = nums[i];
                prevCnt = 1;
                cnt++;
                nums[j++] = nums[i];
            }
        }

        return cnt;
    }
};