/**
 * Subtree of Another Tree
 */

#include "iostream"
#include "utils/Tree.h"
using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSame(root, subRoot)) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        return isSubtree(root ->left, subRoot)
            || isSubtree(root ->right, subRoot); 
    }

    bool isSame(TreeNode* rootA, TreeNode* rootB) {
        if (rootA == nullptr && rootB == nullptr) {
            return true;
        }
        
        if (rootA == nullptr || rootB == nullptr) {
            return false;
        }

        return rootA ->val == rootB ->val
            && isSame(rootA ->left, rootB ->left)
            && isSame(rootA ->right, rootB ->right);
    }
};

