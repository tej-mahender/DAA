#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

struct State {
    int cost;
    int level;
    vector<int> assignment;
    vector<bool> assigned;
};

struct CompareState {
    bool operator()(const State& s1, const State& s2) const {
        return s1.cost > s2.cost;
    }
};

pair<int, vector<int>> solveAssignmentProblem(const vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();
    priority_queue<State, vector<State>, CompareState> pq;

    State initial_state = {0, 0, vector<int>(n), vector<bool>(n, false)};
    pq.push(initial_state);

    int minCost = INF;
    vector<int> minAssignment;

    while (!pq.empty()) {
        State current_state = pq.top();
        pq.pop();

        if (current_state.level == n) {
            if (current_state.cost < minCost) {
                minCost = current_state.cost;
                minAssignment = current_state.assignment;
            }
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (!current_state.assigned[i]) {
                State new_state = current_state;
                new_state.assignment[new_state.level] = i;
                new_state.assigned[i] = true;
                new_state.cost += costMatrix[new_state.level][i];
                new_state.level++;
                int lower_bound = new_state.cost;
                for (int j = new_state.level; j < n; ++j) {
                    int min_cost = INF;
                    for (int k = 0; k < n; ++k) {
                        if (!new_state.assigned[k] && costMatrix[j][k] < min_cost) {
                            min_cost = costMatrix[j][k];
                        }
                    }
                    lower_bound += min_cost;
                }
                if (lower_bound < minCost) {
                    pq.push(new_state);
                }
            }
        }
    }

    return {minCost, minAssignment};
}

int main() {
    int n;
    cout << "Enter the number of persons/jobs: ";
    cin >> n;

    vector<vector<int>> costMatrix(n, vector<int>(n));
    cout << "Enter the cost matrix "<< endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> costMatrix[i][j];
        }
    }

    pair<int, vector<int>> result = solveAssignmentProblem(costMatrix);
    int minCost = result.first;
    vector<int> assignments = result.second;
    cout << "Minimum cost: " << minCost << endl;
    cout << "Assignments: "<<endl;
    for (int i = 0; i < assignments.size(); ++i) {
        cout << "Person " << (i + 1) <<":"<< (assignments[i] + 1) <<endl;
    }
    cout << endl;
    return 0;
}
