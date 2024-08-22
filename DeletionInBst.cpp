#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void deleteNode(TreeNode* &root, int val) {
    if (root == nullptr) {
        return;
    }

    if (root->val > val) {
        if (root->left == nullptr) {
            return;
        }
        if (root->left->val == val) {
            TreeNode* l = root->left;
            if (l->left == nullptr && l->right == nullptr) { // 0 child
                root->left = nullptr;
                delete l;
            } else if (l->left == nullptr || l->right == nullptr) { // 1 child
                if (l->left != nullptr) {
                    root->left = l->left;
                } else {
                    root->left = l->right;
                }
                delete l;
            } else { // 2 child
                TreeNode* curr = l;
                TreeNode* pred = curr->left;
                while (pred->right != nullptr) {
                    pred = pred->right;
                }
                deleteNode(root->left, pred->val);
                pred->left = curr->left;
                pred->right = curr->right;
                root->left = pred;
            }
        } else {
            deleteNode(root->left, val);
        }
    } else {
        if (root->right == nullptr) {
            return;
        }
        if (root->right->val == val) {
            TreeNode* r = root->right;
            if (r->left == nullptr && r->right == nullptr) { // 0 child
                root->right = nullptr;
                delete r;
            } else if (r->left == nullptr || r->right == nullptr) { // 1 child
                if (r->right != nullptr) {
                    root->right = r->right;
                } else {
                    root->right = r->left;
                }
                delete r;
            } else { // 2 child
                TreeNode* curr = r;
                TreeNode* pred = curr->left;
                while (pred->right != nullptr) {
                    pred = pred->right;
                }
                deleteNode(root->right, pred->val);
                pred->left = curr->left;
                pred->right = curr->right;
                root->right = pred;
            }
        } else {
            deleteNode(root->right, val);
        }
    }
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    deleteNode(root, 4);

    // Displaying the modified tree
    // (You can print the tree using in-order, pre-order, or post-order traversal)

    // Remember to free allocated memory to avoid memory leaks
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
