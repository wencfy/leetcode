/**
 * Subtree of Another Tree
 */

#include "iostream"
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

