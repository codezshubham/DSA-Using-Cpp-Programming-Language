#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLL {
public:
    Node* head;
    int size;

    DoublyLL(){
        this->head = nullptr;
        this->size = 0;
    }
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
        cout << endl;
}

Node* insertAtBegin(Node* head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    if (head != nullptr) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

Node* insertAtEnd(Node* head, int val) {
    Node* temp = head;
    Node* tempe = new Node(val);
    if (head == nullptr) {
        return tempe;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = tempe;
    tempe->prev = temp;
    return head;
}

Node* insertAtIndex(Node* head, int idx, int val) {
    if (idx < 1) {
        return head;
    }

    Node* temp = head;
    for (int i = 1; i < idx - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        return head;
    }

    Node* t = new Node(val);
    t->prev = temp;
    t->next = temp->next;

    if (temp->next != nullptr) {
        temp->next->prev = t;
    }

    temp->next = t;
    return head;
}

Node* deleteAtBegin(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    head = head->next;
    head->prev = nullptr;
    delete head->prev;
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteAtIndex(Node* head, int idx) {
    if (head == nullptr || idx < 1) {
        return head;
    }

    if (idx == 1) {
        Node* newHead = head->next;
        if (newHead != nullptr) {
            newHead->prev = nullptr;
        }
        delete head;
        return newHead;
    }

    Node* temp = head;
    for (int i = 1; i < idx - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        return head;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;

    if (temp->next != nullptr) {
        temp->next->prev = temp;
    }

    delete toDelete;
    return head;
    }
};

int main() {
    DoublyLL dl;
    Node* a = new Node(5);
    Node* b = new Node(4);
    Node* c = new Node(3);
    Node* d = new Node(2);
    Node* e = new Node(1);
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;

    dl.display(a);

    Node* x = dl.insertAtBegin(a, 7);
    dl.display(x);

    Node* y = dl.insertAtEnd(x, 6);
    dl.display(y);

    Node* z = dl.insertAtIndex(y, 5, 0);
    dl.display(z);

    Node* w = dl.deleteAtBegin(z);
    dl.display(w);

    Node* v = dl.deleteAtEnd(w);
    dl.display(v);

    Node* u = dl.deleteAtIndex(v, 2);
    dl.display(u);

    // Clean up memory
    while (u != nullptr) {
        Node* nextNode = u->next;
        delete u;
        u = nextNode;
    }

    return 0;
}
