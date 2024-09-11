struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

class Tree {
private:
    TreeNode *root;
    void preOrder(TreeNode *node);
    void inOrder(TreeNode *node);
    void postOrder(TreeNode *node);
public:
    Tree(TreeNode *root);
    void visit(TreeNode *node);
    void preOrderNonRecur();
    void preOrder();
    void inOrderNonRecur();
    void inOrder();
    void postOrderNonRecur();
    void postOrder();
};