#include <iostream>
using namespace std;

const int MAX_VERTICES = 20;

void listEdges(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    cout << endl << "Edges and their counts:" << endl;

    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            int count = adjacencyMatrix[i][j];

            if (count > 0)
            {
                cout << "Edge: " << i+1 << " -> " << j+1 << ", Count: " << count << endl;
            }
        }
    }
}

void printAdjacencyMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    cout << endl << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    cout << endl << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            cout << "Matrix Entry ["<< i+1 <<"]["<< j+1 <<"] : ";
            cin >> adjacencyMatrix[i][j];
        }
    }

    printAdjacencyMatrix(adjacencyMatrix, numVertices);
    listEdges(adjacencyMatrix, numVertices);

    return 0;
}
