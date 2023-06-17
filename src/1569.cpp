/**
 * Number of Ways to Reorder Array to Get Same BST
*/

#include "iostream"
using namespace std;

class Solution {
private:
    int modulo = 1000000007;
    vector<vector<int>> dp = vector<vector<int>>(1000, vector<int>(1000, 1));
public:
    int numOfWays(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j < nums.size(); j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % modulo;
            }
        }

        return (getAns(nums) - 1) % modulo;
    }

    int getAns(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0) {
            return 1;
        }

        int root = nums.front();
        vector<int> leftTree;
        vector<int> rightTree;
        for (int num: nums) {
            if (num < root) {
                leftTree.push_back(num);
            } else if (num > root) {
                rightTree.push_back(num);
            }
        }

        long ret = ((long) getAns(leftTree) * getAns(rightTree)) % modulo
                 * dp[leftTree.size()][rightTree.size()] % modulo;

        return ret;
    }
};

int main() {
    vector<int> nums = {2, 1, 3};
    cout << (new Solution()) ->numOfWays(nums) << endl;
}