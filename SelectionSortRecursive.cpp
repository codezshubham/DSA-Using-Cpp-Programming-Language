#include <iostream>
using namespace std;
void selectionSort(int arr[], int n, int i) {
    if (i > (n - 1)) {
        return;
    }

    int min_index = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[min_index]) {
            min_index = j;
        }
    }

    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;

    selectionSort(arr, n, i + 1);
}

int main() {
    int arr[] = {7, 4, 1, 2, 100, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n, 0);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
