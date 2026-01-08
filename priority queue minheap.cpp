#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // MIN HEAP

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    cout << "Min Heap elements:\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";   // smallest element
        pq.pop();
    }

    return 0;
}
