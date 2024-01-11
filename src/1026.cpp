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
    int maxDiff = -1;
    int maxAncestorDiff(TreeNode* root) {
        traverse(root, root->val, root->val);
        return maxDiff;
    }

    void traverse(TreeNode *node, int maxVal, int minVal) {
        maxDiff = max(maxDiff, node->val - minVal);
        maxDiff = max(maxDiff, maxVal - node->val);
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);
        if (node->left) {
            traverse(node->left, maxVal, minVal);
        }
        if (node->right) {
            traverse(node->right, maxVal, minVal);
        }
    }
};