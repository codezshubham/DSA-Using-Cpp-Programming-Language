#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

void bfs(Node* root) {
    queue<Node*> q;
    if (root != nullptr) q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
        cout << temp->val << " ";
        q.pop();
    }
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

    bfs(root);

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


// #include <iostream>

// template <typename T>
// class Queue {
// private:
//     struct Node {
//         T data;
//         Node* next;
//         Node(T value) : data(value), next(nullptr) {}
//     };

//     Node* front;
//     Node* rear;

// public:
//     Queue() : front(nullptr), rear(nullptr) {}

//     void enqueue(T value) {
//         Node* newNode = new Node(value);
//         if (rear == nullptr) {
//             front = rear = newNode;
//         } else {
//             rear->next = newNode;
//             rear = newNode;
//         }
//     }

//     T dequeue() {
//         if (front == nullptr) {
//             // Queue is empty
//             return T();
//         }
//         T value = front->data;
//         Node* temp = front;
//         front = front->next;
//         if (front == nullptr) {
//             // Queue is empty after dequeue
//             rear = nullptr;
//         }
//         delete temp;
//         return value;
//     }

//     bool isEmpty() {
//         return front == nullptr;
//     }
// };

// class TreeNode {
// public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
// };

// void bfs(TreeNode* root, Queue<TreeNode*>& q) {
//     if (root != nullptr) q.enqueue(root);

//     while (!q.isEmpty()) {
//         TreeNode* temp = q.dequeue();
//         if (temp->left != nullptr) q.enqueue(temp->left);
//         if (temp->right != nullptr) q.enqueue(temp->right);
//         std::cout << temp->val << " ";
//     }
// }

// int main() {
//     Queue<TreeNode*> q;
//     TreeNode* root = new TreeNode(5);
//     TreeNode* a = new TreeNode(4);
//     TreeNode* b = new TreeNode(7);
//     root->left = a;
//     root->right = b;
//     TreeNode* c = new TreeNode(2);
//     TreeNode* d = new TreeNode(3);
//     a->left = c;
//     a->right = d;
//     TreeNode* e = new TreeNode(6);
//     TreeNode* f = new TreeNode(1);
//     b->left = e;
//     b->right = f;

//     bfs(root, q);

//     // Remember to free allocated memory to avoid memory leaks
//     delete root;
//     delete a;
//     delete b;
//     delete c;
//     delete d;
//     delete e;
//     delete f;

//     return 0;
// }
