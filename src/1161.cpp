/**
 * Maximum Level Sum of a Binary Tree
 * 
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 * Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
 */

#include "iostream"
#include "limits.h"
#include "queue"
#include "utils/Tree.h"
using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;

        int maxSum = INT_MIN;
        int maxLevel;
        int levelSum = 0;
        int curLevel = 1;

        // {level, value}
        q.push({1, root});
        while (!q.empty()) {
            auto levelNodePair = q.front();
            q.pop();
            if (curLevel == levelNodePair.first) {
                levelSum += levelNodePair.second->val;
            } else {
                if (levelSum > maxSum) {
                    cout << curLevel << ": " << levelSum << " " << maxSum << endl;
                    maxSum = levelSum;
                    maxLevel = curLevel;
                }
                levelSum = levelNodePair.second->val;
                curLevel = levelNodePair.first;
            }

            if (levelNodePair.second->left) {
                q.push({levelNodePair.first + 1, levelNodePair.second->left});
            }
            if (levelNodePair.second->right) {
                q.push({levelNodePair.first + 1, levelNodePair.second->right});
            }
        }

        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = curLevel;
        }

        return maxLevel;
    }
};