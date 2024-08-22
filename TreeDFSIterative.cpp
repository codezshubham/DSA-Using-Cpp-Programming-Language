#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        result.push_back(temp->val);

        if (temp->right != nullptr) {
            st.push(temp->right);
        }
        if (temp->left != nullptr) {
            st.push(temp->left);
        }
    }

    return result;
}

vector<int> inorderTraversal(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* temp = st.top();
        if (temp->left != nullptr) {
            st.push(temp->left);
            temp->left = nullptr;  // break the link
        } else {
            st.pop();
            result.push_back(temp->val);
            if (temp->right != nullptr) st.push(temp->right);
        }
    }

    return result;
}
vector<int> postorderTraversal(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if (temp->left != nullptr) st1.push(temp->left);
        if (temp->right != nullptr) st1.push(temp->right);
    }

    while (!st2.empty()) {
        result.push_back(st2.top()->val);
        st2.pop();
    }

    return result;
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

    // vector<int> result = preorderTraversal(root);

    // cout << "Preorder Traversal: "<<endl;
    // for (int num : result) {
    //     cout << num << " ";
    // }

    // vector<int> result1 = inorderTraversal(root);

    // cout <<endl<< "Inorder Traversal: "<<endl;
    // for (int num : result1) {
    //     cout << num << " ";
    // }

    vector<int> result2 = postorderTraversal(root);

    cout <<endl<< "Postorder Traversal: "<<endl;
    for (int num : result2) {
        cout << num << " ";
    }
}