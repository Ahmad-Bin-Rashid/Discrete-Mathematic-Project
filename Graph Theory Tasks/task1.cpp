#include <iostream>
using namespace std;


int main() {
    const int MAX_VERTICES = 20;
    int numEdges;
    int degree[MAX_VERTICES] = {0};
    int u, v;

    cout << endl << "Enter the number of edges: ";
    cin >> numEdges;
    cout << endl << "Enter the vertex pairs for each edge: " << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        cout << "Vertex Pair for edge \'"<< i+1 << "\' : ";
        cin >> u >> v;

        degree[u]++;
        degree[v]++;
    }

    cout << endl << "Degree of each vertex: " << endl;
    for (int i = 0; i < MAX_VERTICES; ++i)
    {
        if (degree[i] > 0) {
            cout << "Vertex " << i << ": " << degree[i] << " degree" << endl;
        }
    }
    return 0;
}

