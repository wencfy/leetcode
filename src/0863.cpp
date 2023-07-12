/**
 * All Nodes Distance K in Binary Tree
 * 
 * Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
 * 
 * You can return the answer in any order.
 */

#include "iostream"
#include "vector"
#include "queue"
#include "map"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    map<TreeNode *, TreeNode *> fa;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markFa(root);
        vector<int> ret;
        map<TreeNode *, bool> visited;

        queue<pair<int, TreeNode*>> q;

        q.push({0, target});
        visited[target] = true;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int level = top.first;
            TreeNode *t = top.second;

            if (level == k) {
                ret.push_back(t->val);
            } else {
                if (t->left && !visited[t->left]) {
                    q.push({level + 1, t->left});
                    visited[t->left] = true;
                }
                if (t->right && !visited[t->right]) {
                    q.push({level + 1, t->right});
                    visited[t->right] = true;
                }
                if (fa[t] && !visited[fa[t]]) {
                    q.push({level + 1, fa[t]});
                    visited[fa[t]] = true;
                }
            }
        }

        return ret;
    }

    void markFa(TreeNode *t) {
        if (t->left) {
            fa[t->left] = t;
            markFa(t->left);
        }

        if (t->right) {
            fa[t->right] = t;
            markFa(t->right);
        }
    }
};