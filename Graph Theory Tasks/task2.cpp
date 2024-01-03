#include <iostream>
using namespace std;

const int MAX_VERTICES = 30;

int main() {
    int numEdges;
    int inDegree[MAX_VERTICES] = {0};
    int outDegree[MAX_VERTICES] = {0};
    int u, v;

    cout << endl << "Enter the number of edges: ";
    cin >> numEdges;
    cout << endl << "Enter the vertex pairs for each directed edge:" << endl;
    
    for (int i = 0; i < numEdges; ++i) {
        cout << "Vertex Pair for directed edge \'" << i + 1 << "\' : ";
        cin >> u >> v;

        // Increment out-degree for u and in-degree for v
        outDegree[u]++;
        inDegree[v]++;
    }

    cout << endl << "Out-degree and In-degree of each vertex:" << endl;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        if (outDegree[i] > 0 || inDegree[i] > 0) {
            cout << "Vertex " << i << ": Out-degree = " << outDegree[i];
            cout << ", In-degree = " << inDegree[i] << endl;
        }
    }
    return 0;
}
