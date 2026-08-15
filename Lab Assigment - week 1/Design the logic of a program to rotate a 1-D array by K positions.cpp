#include <iostream>
using namespace std;

#define SIZE 100

void leftRotate(int arr[], int n, int k) {
    k = k % n;
    int temp[SIZE];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}

void rightRotate(int arr[], int n, int k) {
    k = k % n;
    int temp[SIZE];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i - k + n) % n];
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}

int main() {
    int arr[] = {11,12,13,14,15};
    int n = 5, k = 2;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    leftRotate(arr, n, k);
    cout << "Left Rotation by " << k << ": ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int arr2[] = {11,12,13,14,15};
    rightRotate(arr2, n, k);
    cout << "Right Rotation by " << k << ": ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    return 0;
}


