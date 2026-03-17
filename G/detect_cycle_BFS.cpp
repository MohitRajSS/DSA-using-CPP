#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detectGraph(int src, int visited[], vector<int> adj[]) {
    visited[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                q.push({i, node});
                visited[i] = 1;
            } else if (parent != i) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]) {
    int visited[v] = {0};
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (detectGraph(i, visited, adj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int v = 5;
    vector<int> adj[v];

    // Example graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    if (isCycle(v, adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
    
    return 0;
}
