#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    Node* root = new Node(5);
    Node* a = new Node(3);
    Node* b = new Node(7);
    root->left = a;
    root->right = b;
    Node* c = new Node(2);
    Node* d = new Node(4);
    a->left = c;
    a->right = d;
    Node* e = new Node(6);
    Node* f = new Node(8);
    b->left = e;
    b->right = f;

    // preOrder(root);
    // std::cout << std::endl;
    inOrder(root);
    // std::cout << std::endl;
    // postOrder(root);

    // Deallocate memory to prevent memory leaks
    delete f;
    delete e;
    delete d;
    delete c;
    delete b;
    delete a;
    delete root;

    return 0;
}