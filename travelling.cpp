#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define m 10

void travellingSalesman(int n,int graph[][m],int s) {
   vector<int>vertex;
   vector<int>Path;
   for(int i=0;i<n;i++){
    if(i!=s)
        vertex.push_back(i);
   }
   int minPath=INT_MAX;
   do{
    int current=0,k=s;
    for(int i=0;i<vertex.size();i++){
        current+=graph[k][vertex[i]];
        k=vertex[i];
    }
       current += graph[k][s];
        if (current < minPath) {
            minPath = current;
            Path = vertex;
        }
   }
   while(next_permutation(vertex.begin(),vertex.end()));
   cout<<"Minimum cost : "<<minPath<<endl;
    cout << "Path: ";
    cout << s << "-";
    for (int v : Path) {
        cout << v << "-";
    }
    cout << s << endl;
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int graph[m][m];
    cout<<"Enter Adjacency matrix: "<<endl;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
                cin>>graph[i][j];
        }
      }
    int s=0;
    travellingSalesman(n,graph,s);
    return 0;
}
