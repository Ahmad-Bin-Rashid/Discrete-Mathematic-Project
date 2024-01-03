#include <iostream>
using namespace std;

const int MAX_VERTICES = 20;

void constructAdjacencyMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numEdges)
{
    int u, v;
    cout << "Enter the vertex pairs for each edge:" << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        cout << "Vertex Pair for undirected edge \'" << i + 1 << "\' : ";
        cin >> u >> v;

        adjacencyMatrix[u][v]++;  // For an undirected graph
        adjacencyMatrix[v][u]++;
    }
}

void printAdjacencyMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= numVertices; ++i)
    {
        for (int j = 1; j <= numVertices; ++j)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numEdges;
    int numVertices;

    cout << endl << "Enter the number of vertices: ";
    cin >> numVertices;

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    constructAdjacencyMatrix(adjacencyMatrix, numEdges);
    printAdjacencyMatrix(adjacencyMatrix, numVertices);

    return 0;
}
