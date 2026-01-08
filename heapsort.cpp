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

// Heapsort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr.data(), i, n);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        Heapify(arr.data(), 0, i); // call max heapify on the reduced heap
    }
}   

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Unsorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}