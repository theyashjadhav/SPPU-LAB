#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    int V;
    vector<vector<int>> adj;

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Depth First Search (DFS) traversal
    void DFS(int s)
    {
        vector<bool> visited(V, false);
        DFSUtil(s, visited);
    }

    // Breadth First Search (BFS) traversal
    void BFS(int s)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int v = q.front();
            cout << v << " ";
            q.pop();

            // Visit all adjacent vertices of the current vertex
            for (int i = 0; i < adj[v].size(); ++i)
            {
                int u = adj[v][i];
                if (!visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }

    // Utility function for DFS traversal
    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        // Recursively visit all adjacent vertices of the current vertex
        for (int i = 0; i < adj[v].size(); ++i)
        {
            int u = adj[v][i];
            if (!visited[u])
            {
                DFSUtil(u, visited);
            }
        }
    }
};

int main()
{
    int nVertex = 0, v, u, nEdges;

    cout << "\nEnter no. of vertices: ";
    cin >> nVertex;

    Graph g(nVertex);

    cout << "\nEnter no. of edges: ";
    cin >> nEdges;

    // Input edges
    for (int i = 0; i < nEdges; i++)
    {
        cout << "\nEnter starting and ending vertex of edge: ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nDFS traversal starting from vertex 0: \n";
    g.DFS(0);
    cout << endl;

    cout << "\nBFS traversal starting from vertex 0: \n";
    g.BFS(0);
    cout << endl;

    return 0;
}


/*

Enter no. of vertex : 7

Enter no. of edge : 6

Enter starting and endding vertex of edge : 0 1

Enter starting and endding vertex of edge : 0 2

Enter starting and endding vertex of edge : 1 3

Enter starting and endding vertex of edge : 1 4

Enter starting and endding vertex of edge : 2 5

Enter starting and endding vertex of edge : 2 6

DFS traversal starting from vertex 0:
0 1 3 4 2 5 6

BFS traversal starting from vertex 0:
0 1 2 3 4 5 6

*/
