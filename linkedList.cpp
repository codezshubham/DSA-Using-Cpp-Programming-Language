#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void insertAtEnd(int val) {
        Node* temp = new Node(val);

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtBegin(int val) {
        Node* temp = new Node(val);

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAt(int idx, int val) {
        Node* t = new Node(val);
        Node* temp = head;

        if (idx == 0) {
            insertAtBegin(val);
            return;
        } else if (idx == size) {
            insertAtEnd(val);
            return;
        } else if (idx < 0 || idx > size) {
            cout << "Wrong Index" << endl;
            return;
        } else {
            for (int i = 1; i <= idx - 1; i++) {
                temp = temp->next;
            }

            t->next = temp->next;
            temp->next = t;
        }
        size++;
    }

    void deleteAtBegin() {
        if (head == nullptr) {
            return;
        }
        head = head->next;
        size--;
    }

    void deleteAtEnd() {
        Node* temp = head;
        if (head == nullptr) {
            return;
        }
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        tail = temp;
        size--;
    }

    void deleteAt(int idx) {
        Node* temp = head;

        for (int i = 1; i <= idx - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        size--;
    }

    int getAt(int idx) {
        Node* temp = head;

        for (int i = 1; i <= idx; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ~LinkedList() {
    //     Node* current = head;
    //     Node* next;
    //     while (current != nullptr) {
    //         next = current->next;
    //         delete current;
    //         current = next;
    //     }
    // }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(7);
    ll.display();
    ll.insertAtEnd(6);
    ll.display();
    ll.insertAtBegin(5);
    ll.display();
    ll.insertAtBegin(4);
    ll.display();
    ll.insertAt(4, 3);
    ll.display();
    ll.insertAt(0, 3);
    ll.display();
    ll.deleteAt(4);
    ll.display();
    ll.deleteAtBegin();
    ll.display();
    ll.deleteAtEnd();
    ll.display();
    return 0;
}
