#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to construct optimal BST and return its cost
int optimalBST(vector<int>p, vector<int>q, int n) {
    vector<vector<int>> w(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> r(n + 1, vector<int>(n + 1, 0));

    // Base case: j - i = 0
    for (int i = 0; i <= n; ++i) {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    for (int d = 1; d <= n; ++d) {
        for (int i = 0; i <= n - d; ++i) {
            int j = i + d;
            w[i][j] = p[j] + q[j] + w[i][j - 1];
            c[i][j] = INT_MAX;
            for (int k = i+1 ; k <= j; ++k) {
                int temp = c[i][k - 1] + c[k][j] + w[i][j];
                if (temp < c[i][j]) {
                    c[i][j] = temp;
                    r[i][j] = k;
                }
            }
        }
    }
    return c[0][n];
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    vector<int> p(n+1); // successful search probabilities
    vector<int> q(n + 1); // unsuccessful search probabilities

    cout << "Enter " << n << " successful probabilities: ";
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    cout << "Enter " << n + 1 << " unsuccessful probabilities: ";
    for (int i = 0; i <= n; ++i)
        cin >> q[i];

    int minCost = optimalBST(p, q, n);
    cout << "The minimum cost of constructing the optimal BST is: " << minCost << endl;

    return 0;
}
