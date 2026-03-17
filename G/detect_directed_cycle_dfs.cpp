#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int visited[], int pathvisited[], vector<int> adj[]) {
    visited[node] = 1;    
    pathvisited[node] = 1;

    for (auto it : adj[node]) {
        if (!visited[it]) {
            if (dfs(it, visited, pathvisited, adj)) {
                return true;
            }
        }
        else if (pathvisited[it] == 1) {
            return true;
        }
    }

    pathvisited[node] = 0;
    return false;
}

bool isCycle(int v, vector<int> adj[]) {
    int visited[v] = {0};
    int pathvisited[v] = {0};

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, pathvisited, adj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int v = 4;
    vector<int> adj[v];
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {1};
    if (isCycle(v, adj)) {
        cout << "The graph has a cycle." << endl;
    } else {
        cout << "The graph does not have a cycle." << endl;
    }
    return 0;
}
