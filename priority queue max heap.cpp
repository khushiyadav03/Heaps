#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;   // MAX HEAP by default

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    cout << "Max Heap elements:\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";   // largest element
        pq.pop();
    }

    return 0;
}
