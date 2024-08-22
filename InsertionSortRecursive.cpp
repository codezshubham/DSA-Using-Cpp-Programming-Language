#include <iostream>
using namespace std;
void insertion(int arr[], int n, int i) {
    if (i >= n) {
        return;
    }

    int j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
    }

    insertion(arr, n, i + 1);
}

int main() {
    int arr[] = {8, 3, 6, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, n, 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
