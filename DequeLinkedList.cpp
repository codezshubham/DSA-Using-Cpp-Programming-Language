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

    class Deque {
    private:
        Node* front;
        Node* rear;
        int size;

    public:
        Deque(){
             this->front = front;
            this->rear = nullptr;
            this->size = 0;
        }

        void addToFront(int data) {
            Node* newNode = new Node(data);
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            size++;
        }

        void addToRear(int data) {
            Node* newNode = new Node(data);
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        int removeFromFront() {
            if (isEmpty()) {
                cout << "Deque is empty" << endl;
            }
            int removedData = front->data;
            if (front == rear) {
                delete front;
                front = rear = nullptr;
            } else {
                Node* temp = front;
                front = front->next;
                front->prev = nullptr;
                delete temp;
            }
            size--;
            return removedData;
        }

        int removeFromRear() {
            if (isEmpty()) {
                cout << "Deque is empty" << endl;
            }
            int removedData = rear->data;
            if (front == rear) {
                delete rear;
                front = rear = nullptr;
            } else {
                Node* temp = rear;
                rear = rear->prev;
                rear->next = nullptr;
                delete temp;
            }
            size--;
            return removedData;
        }

        int peekFront() {
            if (isEmpty()) {
                cout << "Deque is empty" << endl;
            }
            return front->data;
        }

        int peekRear() {
            if (isEmpty()) {
                cout << "Deque is empty" << endl;
            }
            return rear->data;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }
    };
int main() {
    Deque dq;
        dq.addToFront(1);
        dq.addToFront(2);
        dq.addToRear(3);
        dq.addToRear(4);
        return 0;
    }
