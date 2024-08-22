#include <iostream>
#include <algorithm>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value){
        this->val = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int size(Node* root) {
    if (root == nullptr) return 0;
    return 1 + size(root->left) + size(root->right);
}

int sum(Node* root) {
    if (root == nullptr) return 0;
    return root->val + sum(root->left) + sum(root->right);
}

int max(Node* root) {
    if (root == nullptr) return numeric_limits<int>::min();
    return max(root->val, max(max(root->left), max(root->right)));
}

int height(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    Node* root = new Node(5);
    Node* a = new Node(4);
    Node* b = new Node(2);
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

    cout << size(root) << endl;
    cout << sum(root) << endl;
    cout << max(root) << endl;
    cout << height(root) << endl;

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
