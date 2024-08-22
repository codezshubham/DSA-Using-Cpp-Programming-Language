#include <iostream>
using namespace std;
class CircularQueueArray {
public:
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);
    int f = -1; // Front
    int r = -1; // Rear
    int size = 0;

    void add(int val) {
        if (size == n) {
            cout << "Queue is full" << endl;
            return;
        } else if (f == -1) {
            f = r = 0;
            arr[0] = val;
        } else if (r == n - 1){
            r = 0;
            arr[0] = val;
        } else {
            arr[++r] = val;
        }
        size++;
    }

    int remove() {
        if (size == 0) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        if (f == n - 1) {
            f = 0;
        }
        int x = arr[f];
        f++;
        size--;
        return x;
    }

    int peek() {
        if (size == 0) {
            cout << "Queue is Empty" << endl;
        }
        return arr[f];
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (size == 0) {
            cout << "Queue Is Empty" << endl;
            return;
        } else {
            if (f <= r) {
                for (int i = f; i <= r; i++) {
                    cout << arr[i] << " ";
                }
            } else {
                // f to n-1
                for (int i = f; i < n; i++) {
                    cout << arr[i] << " ";
                }
                // 0 to r
                for (int i = 0; i <= r; i++) {
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueueArray q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    q.display();
    q.add(6);
    // q.remove();  //2 3 4 5
    // q.display();
    cout << q.peek() << endl;
    cout << q.getSize() << endl;

    return 0;
}
