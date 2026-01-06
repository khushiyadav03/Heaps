#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    int* arr;          
    int size;          // current elements
    int total_size;    // capacity

public:
    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value) {
        if (size == total_size) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << value << " inserted into heap\n";
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap() {
        delete[] arr;
    }
};
