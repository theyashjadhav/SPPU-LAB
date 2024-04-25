#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <omp.h>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void BFS(int startVertex) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            #pragma omp parallel for
            for (int i = 0; i < adjList[currentVertex].size(); ++i) {
                int neighbor = adjList[currentVertex][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(adjList.size(), false);
        stack<int> stk;
        stk.push(startVertex);

        while (!stk.empty()) {
            int currentVertex = stk.top();
            stk.pop();
            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;

                #pragma omp parallel for
                for (int i = 0; i < adjList[currentVertex].size(); ++i) {
                    int neighbor = adjList[currentVertex][i];
                    if (!visited[neighbor]) {
                        stk.push(neighbor);
                    }
                }
            }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);
    cout << endl;

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
