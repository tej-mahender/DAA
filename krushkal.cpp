#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
#define m 10
struct Edge {
    int src, dest, weight;
};
int parent[m];
int find(int i) {
    while (parent[i] != -1)
        i = parent[i];
    return i;
}
void unionSets(int i, int j) {
    parent[i] = j;
}
void krushkals(int graph[][m], Edge edges[], int numEdges, int n) {
    int edgeCount = 0;
    sort(edges, edges + numEdges, [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    for (int i = 1; i <= n; i++)
        parent[i] = -1;
    cout << endl<< "Minimum Spanning Tree (MST) Edges (Kruskal's Algorithm): "<<endl;
    for (int i = 0; i < numEdges && edgeCount < n - 1; i++) {
        int set1 = find(edges[i].src);
        int set2 = find(edges[i].dest);
        if (set1 != set2) {
            cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
            unionSets(set1, set2);
            edgeCount++;
        }
    }
}
int main() {
    int n, Edges,numEdges = 0;
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
     Edge edges[Edges];
    for (int i = 0; i < Edges; i++) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;
         graph[src][dest]=weight;
        graph[dest][src]=weight;
        edges[numEdges].src = src;
        edges[numEdges].dest = dest;
        edges[numEdges].weight = weight;
        numEdges++;
    }
    krushkals(graph, edges, numEdges,n);
    return 0;
}
