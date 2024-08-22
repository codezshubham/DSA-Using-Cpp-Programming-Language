#include <iostream>
#include <algorithm>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;

    int leftH = height(root->left);
    if (root->left != nullptr)
        leftH++;

    int rightH = height(root->right);
    if (root->right != nullptr)
        rightH++;

    int d = leftH - rightH;
    if (d < 0)
        d = -d;

    if (d > 1)
        return false;

    return (isBalanced(root->left) && isBalanced(root->right));
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if (isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    // Remember to free allocated memory to avoid memory leaks
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
