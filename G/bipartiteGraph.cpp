#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 1;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int V = 4;
    vector<vector<int>> adj = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (isBipartite(V, adj)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }
    return 0;
}
