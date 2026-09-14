#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i=0; i<size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed into stack." << endl;
    }

    void pop() {
        if(q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << q.front() << " popped from stack." << endl;
        q.pop();
    }

    void peek() {
        if(q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << q.front() << endl;
    }

    void display() {
        if(q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        queue<int> temp = q;
        while(!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue s;
    s.push(19);
    s.push(39);
    s.push(59);
    s.push(79);
    s.display();
    s.pop();
    s.peek();
    s.display();
    return 0;
}
