#include <iostream>
using namespace std;

#define SIZE 10

void transposeMatrix(int A[SIZE][SIZE], int r, int c) {
    cout << "Transpose:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << A[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[SIZE][SIZE] = {{1,2,3},{4,5,6}};
    transposeMatrix(A, 2, 3);
    return 0;
}
