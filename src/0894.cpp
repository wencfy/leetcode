/**
 * All Possible Full Binary Trees
 * 
 * Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
 * 
 * Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
 * 
 * A full binary tree is a binary tree where each node has exactly 0 or 2 children.
 */

#include "iostream"
#include "vector"
#include "utils/Tree.h"
using namespace std;

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
        dp[0] = {};
        dp[1] = {new TreeNode()};
        for (int i = 2; i <= n; i++) {
            for (int l = 0; l + 1 <= i; l++) {
                int r = i - l - 1;
                for (auto leftTree: dp[l]) {
                    for (auto rightTree: dp[r]) {
                        TreeNode* root = new TreeNode();
                        root->left = leftTree;
                        root->right = rightTree;
                        dp[i].push_back(root);
                    }
                }
            }
        }

        return dp[n];
    }
};