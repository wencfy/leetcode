#include "iostream"
#include "sstream"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }

private:
    void serialize(TreeNode* root, ostringstream &os) {
        if (root == nullptr) {
            os << " #";
            return ;
        } else {
            os << " " << root->val;
            serialize(root->left, os);
            serialize(root->right, os);
        }
    }

    TreeNode *deserialize(istringstream &is) {
        string s;
        is >> s;
        if (s == "#") {
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(s));
        node->left = deserialize(is);
        node->right = deserialize(is);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));