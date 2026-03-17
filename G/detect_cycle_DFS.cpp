#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], int visited[]) {
    visited[node] = 1;
    for (auto i : adj[node]) {
        if (!visited[i]) {
            if (dfs(i, node, adj, visited)) {
                return true;
            }
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int visited[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {  // Start DFS with no parent (-1)
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;  // Number of vertices
    vector<int> adj[V];
    
    // Example edges for a graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1); // This edge introduces a cycle

    if (isCycle(V, adj)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
