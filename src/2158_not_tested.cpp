#include "iostream"
#include "vector"
using namespace std;

class Node {
public:
    Node *lNode;
    Node *rNode;
    int l;
    int r;
    int mid;
    int val;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->val = 0;
    }
};

class SegmentTree {
    Node *root;
public:
    SegmentTree() {
        root = new Node(1, 100001);
        pushDown(root);
    }

    void pushDown(Node *node) {
        if (node->l >= node->r) {
            return;
        }
        node->lNode = new Node(node->l, node->mid);
        node->rNode = new Node(node->mid+1, node->r);
        pushDown(node->lNode);
        pushDown(node->rNode);
    }

    void modify(int l, int r) {
        modify(root, l, r);
    }

    void modify(Node *node, int l, int r) {
        if (node->l == node->r) {
            if (l <= node->l && r >= node->l) {
                node->val = 1;
            }
            return;
        } else {
            modify(node->lNode, l, r);
            modify(node->rNode, l, r);
            node->val = node->lNode->val + node->rNode->val;
        }
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node *node) {
        if (!node) {
            return 0;
        }
        if (l > r) {
            return 0;
        }
        if (node->l >= l && node->r <= r) {
            return node->val;
        }
        int v = 0;
        if (r >= node->mid) {
            v += query(l, r, node->rNode);
        }
        if (l <= node->mid + 1) {
            v += query(l, r, node->lNode);
        }
        return v;
    }
};

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> ret;
        SegmentTree *tree = new SegmentTree();

        for (auto a: paint) {
            int l = a[0];
            int r = a[1] - 1;
            cout << l << " " << r << endl;
            int cnt = tree->query(l, r);
            cout << cnt << endl;
            ret.push_back(r - l + 1 - cnt);
            tree->modify(l, r);
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> paint = {{1, 4}, {5, 8}, {4, 7}};
    vector<int> res = (new Solution())->amountPainted(paint);
    for (auto a: res) {
        cout << a << " ";
    }
    cout << endl;
}