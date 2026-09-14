#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s1 = "Hello  Worl", s2 = "Goodbye World";
    cout << " Concatenation: " << s1 + s2 << endl;

    reverse(s1.begin(), s1.end());
    cout << "Reverse: " << s1 << endl;

    string s3 = "education";
    string noVowels = "";
    for(char c : s3) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')) noVowels += c;
    }
    cout << "Without vowels: " << noVowels << endl;

    string arr[] = {"Orange","apple","cherry"};
    sort(arr, arr+3);
    cout << "Sorted strings: ";
    for(string str: arr) cout << str << " ";
    cout << endl;

    char ch = 'A';
    cout << "Lowercase: " << (char)tolower(ch) << endl;
}
