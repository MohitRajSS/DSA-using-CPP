#include <queue>
#include <vector>
#include <iostream>
using namespace std;

vector<int> bfs(vector<int> adj[], int V) {
    int vis[V] = {0};
    vis[0] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void addEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Print_ans(vector<int> bfs) {
    for (int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> adj[6];
    addEdge(0, 1, adj);
    addEdge(1, 2, adj);
    addEdge(1, 3, adj);
    addEdge(0, 4, adj);

    vector<int> ans = bfs(adj, 6);
    Print_ans(ans);

    return 0;
}
