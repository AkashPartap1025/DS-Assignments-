#include <iostream>
using namespace std;

#define SIZE 10

void multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!\n";
        return;
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE] = {{1,2,3},{4,5,6}};
    int B[SIZE][SIZE] = {{7,8},{9,10},{11,12}};
    int C[SIZE][SIZE];

    multiplyMatrices(A, B, C, 2, 3, 3, 2);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
