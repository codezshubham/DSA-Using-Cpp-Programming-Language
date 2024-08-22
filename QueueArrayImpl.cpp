#include <iostream>
using namespace std;
class QueueArray {
private:
    int* arr;
    int f;  // Front
    int r;  // Rear
    int size;

public:
    QueueArray(){
        arr = new int[5];
        f = -1;
        r = -1;
        size = 0;
    }

    void add(int val) {
        if (r == 4) {
            cout << "Queue is full" << endl;
            return;
        }

        if (f == -1) {
            f = r = 0;
            arr[0] = val;
        } else {
            arr[++r] = val;
        }

        size++;
    }

    int remove() {
        if (size == 0) {
            cout << "Queue Is Empty" << endl;
            return -1;
        }

        int x = arr[f++];
        size--;
        return x;
    }

    int peek() {
        if (size == 0) {
            cout << "Queue Is Empty" << endl;
            return -1;
        }
        return arr[f];
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void display() {
        if (size == 0) {
            cout << "Queue Is Empty" << endl;
            return;
        }

        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~QueueArray() {
        delete[] arr;
    }
};

int main() {
    QueueArray q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    q.display();
    q.remove();
    q.display();
    cout << q.getSize() << endl;

    return 0;
}
