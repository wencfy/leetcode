/**
 * Minimum Depth of Binary Tree
 * 
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "iostream"
#include "queue"
#include "utils/Tree.h"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        if (root) {
            q.push({root, 1});
        }

        int cur = 0;
        bool c = true;
        while (!q.empty() && c) {
            c = false;
            TreeNode *p = q.front().first;
            cur = q.front().second;
            q.pop();

            
            if (p->left) {
                q.push({p->left, cur + 1});
                c = true;
            }

            if (p->right) {
                q.push({p->right, cur + 1});
                c = true;
            }
        }

        return cur;
    }
};