#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

string reverseString(string str) {
    Stack s;
    for (char c : str) {
        s.push(c);
    }

    string rev = "";
    while (!s.isEmpty()) {
        rev += s.pop(); 
    }
    return rev;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = reverseString(input);
    cout << "Reversed string: " << output << endl;

    return 0;
}
