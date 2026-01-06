#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    int* arr;
    int size;
    int total_size;

public:
    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // INSERT INTO HEAP
    void insert(int value) {
        if (size == total_size) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // Heapify Up
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << value << " inserted into heap\n";
    }

    // DELETE ROOT (MAX ELEMENT)
    void deletion() {
        if (size == 0) {
            cout << "Heap Underflow\n";
            return;
        }

        cout << arr[0] << " deleted from heap\n";

        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    // HEAPIFY DOWN
    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void print() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Heap elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

// ----------- MAIN FUNCTION (RUN HERE) -----------
int main() {
    MaxHeap h(10);

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(5);
    h.insert(20);

    h.print();

    h.deletion();   // delete max
    h.print();

    h.deletion();   // delete next max
    h.print();

    return 0;
}
