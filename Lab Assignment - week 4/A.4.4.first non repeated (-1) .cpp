#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[256] = {0};

    for (char c : str) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "First non-repeating characters: ";
    firstNonRepeating(input);

    return 0;
}
