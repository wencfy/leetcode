#include "iostream"
#include "Tree.h"
#include "queue"
using namespace std;

struct Node {
    TreeNode *node;
    long long level;
    long long idx;
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<Node> q;
        q.push({root, 0, 0});
        long long curLevel = 0;
        long long curIdx = 0;
        long long maxLen = 0;
        while (!q.empty()) {
            auto a = q.front();
            q.pop();

            if (curLevel < a.level) {
                curLevel = a.level;
                curIdx = a.idx;
            } else {
                long long curLen = a.idx - curIdx;
                maxLen = maxLen > curLen ? maxLen : curLen;
            }

            if (a.node->left) {
                q.push({a.node->left, a.level + 1, (a.idx - curIdx) * 2});
            }
            if (a.node->right) {
                q.push({a.node->right, a.level + 1, (a.idx - curIdx) * 2 + 1});
            }
        }
        return maxLen + 1;
    }
};