#include <iostream>
// #include <algorithm>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

int height(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void nthLevel(Node* root, int n) {
    if (n == 1) {
        cout << root->val << " ";
        return;
    }
    if (root->left != nullptr) nthLevel(root->left, n - 1);
    if (root->right != nullptr) nthLevel(root->right, n - 1);
}

int main() {
    Node* root = new Node(5);
    Node* a = new Node(4);
    Node* b = new Node(7);
    root->left = a;
    root->right = b;
    Node* c = new Node(2);
    Node* d = new Node(3);
    a->left = c;
    a->right = d;
    Node* e = new Node(6);
    Node* f = new Node(1);
    b->left = e;
    b->right = f;

    int level = height(root) + 1;
    for (int i = 1; i <= level; i++) {
        nthLevel(root, i);
        cout << endl;
    }

    // Remember to free allocated memory to avoid memory leaks
    delete root;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;

    return 0;
}
