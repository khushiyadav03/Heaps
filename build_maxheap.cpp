#include <bits/stdc++.h>
using namespace std;

// Heapify function (heapify down)
void Heapify(int arr[], int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);
        Heapify(arr, largest, n);
    }
}

// Build Max Heap
void BuildMaxHeap(int arr[], int n) {
    // start from last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}

// Print heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 5, 20, 2, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printHeap(arr, n);

    BuildMaxHeap(arr, n);

    cout << "Max Heap:\n";
    printHeap(arr, n);

    return 0;
}
