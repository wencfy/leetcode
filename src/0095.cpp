/**
 * Unique Binary Search Trees II
 * 
 * Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
 */

#include "iostream"
#include "vector"

// #include "utils/Tree.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp = vector<vector<vector<TreeNode*>>>(n + 2, vector<vector<TreeNode*>>(n + 2, vector<TreeNode*>()));

        for (int i = 1; i <= n; i++) {
            TreeNode* ptr = new TreeNode(i);
            dp[i][i].push_back(ptr);
        }

        for (int dis = 1; dis < n; dis++) {
            for (int i = 1; i + dis <= n; i++) {
                for (int mid = i; mid <= i + dis; mid++) {
                    if (!dp[i][mid - 1].size()) {
                        dp[i][mid - 1].push_back(nullptr);
                    }

                    if (!dp[mid + 1][i + dis].size()) {
                        dp[mid + 1][i + dis].push_back(nullptr);
                    }

                    for (auto p: dp[i][mid - 1]) {
                        for (auto q: dp[mid + 1][i + dis]) {
                            TreeNode* ptr = new TreeNode(mid);
                            ptr->left = p;
                            ptr->right = q;
                            dp[i][i + dis].push_back(ptr);
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }
};

int main() {
    (new Solution())->generateTrees(8);
}