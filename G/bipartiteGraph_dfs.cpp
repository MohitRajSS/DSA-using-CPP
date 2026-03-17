#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
    color[node] = col; 
    for (auto it : adj[node]) {
        if (color[it] == -1) { 
            if (!dfs(it, !col, color, adj)) {
                return false;
            }
        } else if (color[it] == col) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { 
            if (!dfs(i, 0, color, adj)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int V = 4;
    vector<int> adj[V];
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    if (isBipartite(V, adj)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }
    return 0;
}
