#include <iostream>
using namespace std;

#define SIZE 100

void removeDuplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
              
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; 
            } else {
                j++; 
            }
        }
    }
}

int main() {
    int arr[SIZE] = {1, 2, 3, 2, 4, 5, 3, 5, 3, 4};
    int n = 10;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}


