#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    for (int i = 0, j = n-1; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    reverseArray(arr, n);

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

