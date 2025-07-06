// Graphs
//  implementing graphs using adjency matrix

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adjMatrix;
    int numNodes;

public:
    Graph(int n) : numNodes(n)
    {
        // Initialize the adjacency matrix with zeros
        adjMatrix.resize(numNodes, vector<int>(numNodes, 0));
    }

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        adjMatrix[u][v] = 1;
        if (!direction)
        {
            adjMatrix[v][u] = 1; // adding the reverse edge also for undirected graph
        }
    }

    void printAdjMatrix()
    {
        // Print the adjacency matrix
        for (int i = 0; i < numNodes; ++i)
        {
            for (int j = 0; j < numNodes; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges in the graph: ";
    cin >> m;

    Graph g(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // creating an undirected graph
    }

    cout << "Adjacency matrix representation of the graph:" << endl;
    g.printAdjMatrix();

    return 0;
}
