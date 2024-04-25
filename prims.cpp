#include <iostream>
#include <climits>
using namespace std;
#define m 10
int parent[m];
void prims(int n,int graph[][m]) {
    int key[m]; // Key values used to pick minimum weight edge in cut
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[1] = 0; // Make key 0 so that this vertex is picked as the first vertex
    for (int j = 1; j <= n - 1; j++) {
        int u = -1;
        for (int v = 1; v <= n; v++) {
            if (key[v] != -1 && (u == -1 || key[v] < key[u]))
                u = v;
        }
        key[u] = -1; // Mark vertex u as processed
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && key[v] != -1 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << endl << "Minimum Spanning Tree (MST) Edges (Prim's Algorithm): "<<endl;
        for (int i = 2; i <= n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}
int main() {
    int n, Edges;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int graph[m][m];
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
                graph[i][j]=0;
        }
      }
    cout << "Enter the number of edges: ";
    cin >> Edges;
    for (int i = 0; i < Edges; i++) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;
        graph[src][dest]=weight;
        graph[dest][src]=weight;
    }
    prims(n,graph);
    return 0;
}
