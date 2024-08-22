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

    class LLStack {
    private:
        Node* head;
        int size;

    public:
        LLStack(){
            this->head = nullptr;
            this->size = 0;
        }

        void push(int x) {
            Node* temp = new Node(x);
            temp->next = head;
            head = temp;
            size++;
        }

        int pop() {
            if (head == nullptr) {
                cout << "Stack is Empty" << endl;
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
            if (head == nullptr) {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return head->val;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return head == nullptr;
        }

        // Simple Display Recursive
        void display() {
            displayRec(head);
            cout << endl;
        }

        void displayRec(Node* h) {
            if (h == nullptr) return;
            displayRec(h->next);
            cout << h->val << " ";
        }

        // Reverse Display
        void revDisplay() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };

int main() {
    LLStack st;
        st.push(4);
        st.display();
        st.push(5);
        st.display();
        st.push(6);
        st.display();
        cout << st.getSize() << endl;
        st.pop();
        st.display();
        st.push(7);
        st.push(8);
        st.display();
        return 0;
}
