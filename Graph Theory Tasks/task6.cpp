#include <iostream>
using namespace std;

const int MAX_VERTICES = 20;
const int MAX_EDGES = 50;

void createIncidenceMatrix(int incidenceMatrix[MAX_VERTICES][MAX_EDGES], int vertexPairs[MAX_EDGES][2], int edgeFrequencies[MAX_EDGES], int numEdges, int numVertices)
{
    for (int i = 0; i < numEdges; ++i)
    {
        int u = vertexPairs[i][0];
        int v = vertexPairs[i][1];
        int frequency = edgeFrequencies[i];

        incidenceMatrix[u][i] = frequency;
        incidenceMatrix[v][i] = frequency;
    }
}

void printIncidenceMatrix(int incidenceMatrix[MAX_VERTICES][MAX_EDGES], int numVertices, int numEdges)
{
    cout << endl << "Incidence Matrix:" << endl;
    for (int i = 1; i <= numVertices; ++i)
    {
        for (int j = 0; j < numEdges; ++j)
        {
            cout << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numEdges;
    int numVertices;
    int vertexPairs[MAX_EDGES][2];
    int edgeFrequencies[MAX_EDGES];
    int incidenceMatrix[MAX_VERTICES][MAX_EDGES] = {0};

    cout << endl << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << endl << "Enter the vertex pairs and frequencies for each edge:" << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        cout << "Edge " << i + 1 << " (vertex pair and frequency): ";
        cin >> vertexPairs[i][0] >> vertexPairs[i][1] >> edgeFrequencies[i];
    }

    createIncidenceMatrix(incidenceMatrix, vertexPairs, edgeFrequencies, numEdges, numVertices);
    printIncidenceMatrix(incidenceMatrix, numVertices, numEdges);

    return 0;
}
