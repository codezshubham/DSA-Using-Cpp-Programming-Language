#include <iostream>
using namespace std;
class Node {
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            this->next = nullptr;
        }
    };

    class QueueLL {
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        QueueLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        }
        void add(int val) {
            Node* temp = new Node(val);
            if (size == 0) {
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            size++;
        }

        int remove() {
            if (size == 0) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            int x = head->val;
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return x;
        }

        int peek() {
            if (size == 0) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            return head->val;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        void display() {
            if (size == 0) {
                cout << "Queue is Empty" << endl;
                return;
            }
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };

int main() {
    QueueLL q;
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);

        q.display();
        q.remove();
        q.display();
        cout << q.peek() << endl;
        return 0;
}
