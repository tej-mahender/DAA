#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void knapsack(vector<int> p, vector<int> w, int n, int m) {
    vector<vector<int>> K(n + 1, vector<int>(m + 1, 0));

    // Filling the K table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w[i - 1] <= j) {
                K[i][j] = max(K[i - 1][j], p[i - 1] + K[i - 1][j - w[i - 1]]);
            } else {
                K[i][j] = K[i - 1][j];
            }
        }
    }

    // Finding the items included in the knapsack
    int weight = m;
    vector<int> includedItems;
    for (int i = n; i > 0 && weight > 0; i--) {
        if (K[i][weight] != K[i - 1][weight]) {
            includedItems.push_back(i - 1);
            weight -= w[i - 1];
        }
    }

    // Printing the solution
    cout << "Solution Vector is: ";
    vector<int> solution(n, 0);
    for (int i : includedItems) {
          solution[i] = 1;
    }
    for (int val : solution) {
        cout << val << " ";
    }

    cout << "\nProfit is: " << K[n][m] << endl;
    cout << "Weight is: " << m - weight << endl;
}

int main() {
    int n, m, val;
    cout << "Enter the number of objects and weight of Bag: ";
    cin >> n >> m;
    vector<int> p;
    vector<int> w;
    cout << "Enter the profits: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        p.push_back(val);
    }
    cout << "Enter the weights: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        w.push_back(val);
    }
    knapsack(p, w, n, m);
    return 0;
}
