#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void add(vector<vector<int>> &A,vector<vector<int>> &B,vector<vector<int>> &C, int n) {
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(vector<vector<int>> &A,vector<vector<int>> &B,vector<vector<int>> &C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void printMatrix(vector<vector<int>> &matrix,  int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void strassenR(vector<vector<int>>&A, vector<vector<int>>&B, vector<vector<int>>&C,int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    } else {
        int newSize = n / 2;
        vector<int> innerVector(newSize, 0);
        // initialize matrices
        vector<vector<int>> A11(newSize, innerVector),
            A12(newSize, innerVector),
            A21(newSize, innerVector),
            A22(newSize, innerVector),
            B11(newSize, innerVector),
            B12(newSize, innerVector),
            B21(newSize, innerVector),
            B22(newSize, innerVector),
            C11(newSize, innerVector),
            C12(newSize, innerVector),
            C21(newSize, innerVector),
            C22(newSize, innerVector),
            s1(newSize, innerVector),
            s2(newSize, innerVector),
            s3(newSize, innerVector),
            s4(newSize, innerVector),
            s5(newSize, innerVector),
            s6(newSize, innerVector),
            s7(newSize, innerVector),
            s8(newSize, innerVector),
            s9(newSize, innerVector),
            s10(newSize, innerVector),
            p1(newSize, innerVector),
            p2(newSize, innerVector),
            p3(newSize, innerVector),
            p4(newSize, innerVector),
            p5(newSize, innerVector),
            p6(newSize, innerVector),
            p7(newSize, innerVector),
            tempMatrixA(newSize, innerVector),
            tempMatrixB(newSize, innerVector);

        // divide matrices into 4 submatrices
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        sub(B12, B22, s1, newSize);// s1 = b12 - b22
        add(A11, A12, s2, newSize); // s2 = a11 + a12
        add(A21, A22, s3, newSize);// s3 = a21 + a22
        sub(B21, B11, s4, newSize);// s4 = b21 - b11
        add(A11, A22, s5, newSize);// s5 = a11 + a22
        add(B11, B22, s6, newSize);// s6 = b11 + b22
        sub(A12, A22, s7, newSize); // s7 = a12 - a22
        add(B21, B22, s8, newSize);// s8 = b21 + b22
        sub(A11, A21, s9, newSize);// s9 = a11 - a21
        add(B11, B12, s10, newSize);// s10 = b11 + b12


        strassenR(A11, s1, p1, newSize); // p1 = a11 * s1
        strassenR(s2, B22, p2, newSize);// p2 = s2 * b22
        strassenR(s3, B11, p3, newSize); // p3 = s3 * b11
        strassenR(A22, s4, p4, newSize);// p4 = a22 * s4
        strassenR(s5, s6, p5, newSize);// p5 = s5 * s6
        strassenR(s7, s8, p6, newSize);// p6 = s7 * s8
        strassenR(s9, s10, p7, newSize); // p7 = s9 * s10

        // c11 = p5 + p4 - p2 + p6
        add(p5, p4, tempMatrixA, newSize);        // p5 + p4
        add(tempMatrixA, p6, tempMatrixB, newSize); // (p5 + p4) + p6
        sub(tempMatrixB, p2, C11, newSize);   // (p5 + p4 + p6) - p2

        add(p1, p2, C12, newSize);// c12 = p1 + p2
        add(p3, p4, C21, newSize);// c21 = p3 + p4

        // c22 = p5 + p1 - p3 + p7
        add(p5, p1, tempMatrixA, newSize);      // p5 + p1
        sub(tempMatrixA, p3, tempMatrixB, newSize); // (p5 + p1) - p3
        sub(tempMatrixB, p7, C22, newSize);   // (p5 + p1 - p3) - p7

        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }

    }
}

int main() {
    int n;
    cout << "Enter no of rows: ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n, 0));
    cout << endl<< "INPUT MATRIX A" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    printMatrix(A, n);
    cout << endl<< "INPUT MATRIX B" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }
    printMatrix(B, n);
    strassenR(A, B, C, n);
    cout << endl<< "MATRIX C = A * B" << endl;
    printMatrix(C, n);
    return 0;
}
