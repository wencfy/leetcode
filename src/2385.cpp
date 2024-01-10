#include "iostream"
#include "queue"
#include "map"
using namespace std;

// Definition for a binary tree node.
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
    map<TreeNode*, TreeNode*> mp;
    map<TreeNode*, bool> vis;
    TreeNode *s;
    int start;
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        addFather(root);
        queue<pair<int, TreeNode*>> q;
        q.push({0, s});
        vis[s] = true;

        int step = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int level = p.first;
            TreeNode *node = p.second;
            step = level;
            
            if (node->left && !vis[node->left]) {
                vis[node->left] = true;
                q.push({level + 1, node->left});
            }

            if (node->right && !vis[node->right]) {
                vis[node->right] = true;
                q.push({level + 1, node->right});
            }

            if (mp[node] && !vis[mp[node]]) {
                vis[mp[node]] = true;
                q.push({level + 1, mp[node]});
            }
        }
        return step;
    }

    void addFather(TreeNode *root) {
        if (!root) {
            return ;
        }
        if (root->val == start) {
            s = root;
        }
        if (root->left) {
            mp.insert({root->left, root});
        }
        addFather(root->left);
        if (root->right) {
            mp.insert({root->right, root});
        }
        addFather(root->right);
    }
};