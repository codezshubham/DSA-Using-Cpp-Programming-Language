#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    if (root->val > val) {
        if (root->left == nullptr)
            root->left = new TreeNode(val);
        else
            insertIntoBST(root->left, val);
    } else {
        if (root->right == nullptr)
            root->right = new TreeNode(val);
        else
            insertIntoBST(root->right, val);
    }

    return root;
}

// Example usage
int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(5);
    insertIntoBST(root, 3);
    insertIntoBST(root, 7);
    insertIntoBST(root, 2);
    insertIntoBST(root, 4);
    insertIntoBST(root, 6);
    insertIntoBST(root, 8);

    // Displaying the modified BST
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
