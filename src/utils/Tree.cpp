#include "Tree.h"
#include "stack"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

Tree::Tree(TreeNode *root) {
    this->root = root;
}

void Tree::visit(TreeNode *node) {
    printf("%d ", node->val);
}

void Tree::preOrder() {
    preOrder(root);
}

void Tree::preOrder(TreeNode *node) {
    if (!node) {
        return;
    }
    visit(node);
    preOrder(node->left);
    preOrder(node->right);
}

void Tree::preOrderNonRecur() {
    TreeNode *node = root;

    std::stack<TreeNode*> st;
    // while (node || !st.empty()) {
    //     if (node) {
    //         visit(node);
    //         if (node->right) {
    //             st.push(node->right);
    //         }
    //         if (node->left) {
    //             st.push(node->left);
    //         }
    //         node = nullptr;
    //     } else {
    //         node = st.top();
    //         st.pop();
    //     }
    // }

    while (node || !st.empty()) {
        if (node) {
            visit(node);
            if (node->right) {
                st.push(node->right);
            }
            node = node->left;
        } else {
            node = st.top();
            st.pop();
        }
    }
}

void Tree::inOrder() {
    inOrder(root);
}

void Tree::inOrder(TreeNode *node) {
    if (!node) {
        return;
    }
    inOrder(node->left);
    visit(node);
    inOrder(node->right);
}

void Tree::inOrderNonRecur() {
    TreeNode *node = root;

    std::stack<TreeNode *> st;
    while (node || !st.empty()) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            node = st.top();
            st.pop();
            visit(node);
            node = node->right;
        }
    }
}

void Tree::postOrder() {
    postOrder(root);
}

void Tree::postOrder(TreeNode *node) {
    if (!node) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    visit(node);
}

void Tree::postOrderNonRecur() {
    TreeNode *node = root;

    std::stack<TreeNode *> st;
    TreeNode *prev = nullptr;
    while (node || !st.empty()) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            TreeNode *top = st.top();
            if (top->right && prev != top->right) {
                node = top->right;
            } else {
                visit(top);
                st.pop();
                prev = top;
                node = nullptr;
            }
        }
    }
}

int main() {
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(3, node7, nullptr);
    TreeNode *node2 = new TreeNode(2, node5, node6);
    TreeNode *node1 = new TreeNode(1, node3, node4);
    TreeNode *node0 = new TreeNode(0, node1, node2);

    Tree *tree = new Tree(node0);
    tree->preOrderNonRecur();
    printf("\n");

    tree->preOrder();
    printf("\n");

    tree->inOrderNonRecur();
    printf("\n");

    tree->inOrder();
    printf("\n");

    tree->postOrderNonRecur();
    printf("\n");

    tree->postOrder();
    printf("\n");
}