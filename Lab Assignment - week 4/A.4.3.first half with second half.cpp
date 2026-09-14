#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements!" << endl;
        return;
    }

    queue<int> q1, q2;

    // Split into two halves
    for (int i = 0; i < n/2; i++) {
        q1.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        q2.push(q.front());
        q.pop();
    }

    // Interleave
    while (!q1.empty() && !q2.empty()) {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
}

int main() {
    queue<int> q;

    // Sample input
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
