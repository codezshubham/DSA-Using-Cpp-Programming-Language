#include <iostream>
using namespace std;
void bubble(int arr[], int n) {
    if (n == 1) {
        return;
    }

    for (int j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }

    bubble(arr, n - 1);
}

int main() {
    int arr[] = {5, 7, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
