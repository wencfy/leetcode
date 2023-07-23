/**
 * Minimum Absolute Difference in BST
 * 
 * Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
*/

#include "iostream"
#include "limits.h"
#include "utils/Tree.h"
using namespace std;

class Solution {
private:
    int prev = -1;
    int minDiff = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        return minDiff;
    }

    void traverse(TreeNode *ptr) {
        if (ptr->left) {
            traverse(ptr->left);
        }
        if (prev == -1) {
            prev = ptr->val;
        } else {
            minDiff = min(minDiff, ptr->val - prev);
            prev = ptr->val;
        }
        if (ptr->right) {
            traverse(ptr->right);
        }
    }
};