#include <iostream>
using namespace std;

int missingLinear(int arr[], int n) {
    int total = (n+1)*(n+2)/2; 
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return total - sum;
}

int main() {
    int arr[] = {1,2,3,5};
    int n = 4;
    cout << "Missing number (Linear): " << missingLinear(arr, n) << endl;
}
