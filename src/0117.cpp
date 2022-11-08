/**
 * Populating Next Right Pointers in Each Node II
 * 
 * Populate each next pointer to point to its next right node.
 * If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 */

#include "iostream"
#include "queue"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    queue<pair<Node*, int>> q;

    Node* connect(Node* root) {
        pushQueue(root, 0);
        while (!q.empty()) {
            pair<Node*, int> nodeInfo = q.front();
            q.pop();

            int level = nodeInfo.second;
            if (!q.empty()) {
                pair<Node*, int> nextNodeInfo = q.front();
                if (level == nextNodeInfo.second) {
                    nodeInfo.first ->next = nextNodeInfo.first;
                }
            }
            pushQueue(nodeInfo.first ->left, level + 1);
            pushQueue(nodeInfo.first ->right, level + 1);
        }
        return root;
    }

    void pushQueue(Node *node, int level) {
        if (node != nullptr) {
            q.push(pair<Node*, int>(node, level));
        }
    }
};

int main() {
    queue<pair<Node*, int>> q;
    Node *node = new Node(1);
    q.push(pair<Node*, int>(node, 1));
    Node *test = q.front().first;
    test ->val = 3;
    cout << node ->val << endl;
}