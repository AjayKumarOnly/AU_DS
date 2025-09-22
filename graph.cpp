#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void BFS(int s) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) visited[i] = false;
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();
            for (auto i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        for (auto i : adj[v]) {
            if (!visited[i]) DFSUtil(i, visited);
        }
    }
    void DFS(int s) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) visited[i] = false;
        DFSUtil(s, visited);
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from node 0: ";
    g.BFS(0);
    cout << "\nDFS starting from node 0: ";
    g.DFS(0);
    return 0;
}
