#include <iostream>
using namespace std;

const int MAX_VERTICES = 20;

bool isBipartite(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int numVertices) 
{
    int color[MAX_VERTICES] = {0};  // 0 => uncolored, 1 => color A, -1 => color B
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    color[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < numVertices; ++v)
        {
            if (graph[u][v] == 1) {
                if (color[v] == 0) {
                    // Color the adjacent vertex with the opposite color
                    color[v] = -color[u];
                    queue[rear++] = v;
                }
                else if (color[v] == color[u]) {
                    return false;  // The graph is not bipartite
                }
            }
        }
    }
    return true;  // The graph is bipartite
}

int main()
{
    int numEdges;
    int numVertices;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int u, v;
    int startVertex;  // Starting vertex for BFS

    cout << endl << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the vertex pairs for each edge:" << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        cout << "Vertex Pair for directed edge \'" << i + 1 << "\' : ";
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;  // For an undirected graph
    }

    startVertex = 1;
    cout << endl;
    if (isBipartite(graph, startVertex, numVertices))
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
