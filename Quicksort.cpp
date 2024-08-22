#include<iostream>
using namespace std;

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i < j) {
        while (A[i] <= pivot) {
            i++;
        }

        while (A[j] > pivot) {
            j--;
        }

        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high) {
    int partitionIndex; // Index of pivot after partition
    if (low >= high) {
        return;
    }
    partitionIndex = partition(A, low, high);
    quickSort(A, low, partitionIndex - 1);  // sort left subarray
    quickSort(A, partitionIndex + 1, high); // sort right subarray
}

int main() {
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);
    printArray(A, n);

    return 0;
}
