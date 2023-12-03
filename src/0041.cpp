#include "iostream"
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int s = nums[i];
            while (s <= n && s >= 1) {
                if (nums[s - 1] == s) {
                    break;
                }
                int tmp = nums[s - 1];
                nums[s - 1] = s;
                s = tmp;
            }
            if (s < 1 && s > n) {
                nums[s - 1] = n + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main() {
    vector<int> vec = {1, 3, 4};
    printf("%d\n", (new Solution())->firstMissingPositive(vec));
}
