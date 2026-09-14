#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed into stack." << endl;
    }

    void pop() {
        if(q1.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << q1.front() << " popped from stack." << endl;
        q1.pop();
    }

    void peek() {
        if(q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << q1.front() << endl;
    }

    void display() {
        if(q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        queue<int> temp = q1;
        while(!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues s;
    s.push(10);
    s.push(35);
    s.push(70);
    s.display();
    s.pop();
    s.peek();
    s.display();
    return 0;
}
