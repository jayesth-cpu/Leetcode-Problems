#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;                   // number of vertices
    vector<vector<int>> adj; // adjacency list representation of the graph
public:
    Graph(int v) : V(v), adj(v) {} // constructor to create a graph with 'v' vertices

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false); // marking all the vertices as not visited
        stack<int> s;                   // create a stack for dfs traversal
        s.push(start);                  // push the start node to the stack
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            cout << node << " ";
            for (int v : adj[node])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    s.push(v);
                }
            }
        }
    }
};

int main()
{
    Graph g(13);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(1, 8);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(8, 12);
    g.addEdge(8, 9);
    g.addEdge(9, 11);
    g.addEdge(9, 10);
    cout << "DFS traversal starting from vertex 1: " << endl;
    g.DFS(1);
    cout << endl;
    return 0;
}
