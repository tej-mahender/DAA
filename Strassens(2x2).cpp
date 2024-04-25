#include <iostream>
using namespace std;

void Strassen(int a[][2], int b[][2], int c[][2], int n) {
    int p, q, r, s, t, u, v;
    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q = b[0][0] * (a[1][0] + a[1][1]);
    r = a[0][0] * (b[0][1] - b[1][1]);
    s = a[1][1] * (b[1][0] - b[0][1]);
    t = b[1][1] * (a[0][0] + a[0][1]);
    u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    v = (b[1][0] + b[1][1]) * (a[0][1] - a[1][1]);
    c[0][0] = p + s-t+v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p + r-q+u;
}

int main() {
    int a[2][2], b[2][2], c[2][2];
   
    // Input matrices a and b
    cout << "Enter elements of matrix a (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of matrix b (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> b[i][j];
        }
    }

    // Perform matrix multiplication
    Strassen(a, b, c, 2);

    // Output result matrix c
    cout << "Resultant matrix c (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
