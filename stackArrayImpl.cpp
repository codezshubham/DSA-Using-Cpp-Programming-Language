#include <iostream>
using namespace std;

class Stack {
public:
    int arr[4];
    int idx;

    Stack(){
        this->idx = 0;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Is Full" << endl;
            return;
        }
        arr[idx] = x;
        idx++;
    }

    int peek() {
        if (idx == 0) {
            cout << "Stack Is Empty" << endl;
            return -1;
        }
        return arr[idx - 1];
    }

    int pop() {
        if (idx == 0) {
            cout << "Stack Is Empty" << endl;
            return -1;
        }
        int top = arr[idx - 1];
        arr[idx - 1] = 0;
        idx--;
        return top;
    }

    int size() {
        return idx;
    }

    bool isEmpty() {
        return idx == 0;
    }

    bool isFull() {
        return idx == sizeof(arr) / sizeof(arr[0]);
    }

    int capacity() {
        return sizeof(arr) / sizeof(arr[0]);
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack Is Empty" << endl;
        }
        for (int i = 0; i <= idx - 1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    cout <<st.isFull() << endl;
    st.push(5);
    st.pop();
    cout << st.peek() << endl;
    cout << st.capacity() << endl;
    return 0;
}
