#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topologicalSort(vector<int> adj[], int V) {
    vector<int> indegree(V, 0);

    // Calculate indegree of each node
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;

    // Push nodes with indegree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // Print topological order
    for (auto it : topo) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Define random edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort: ";
    topologicalSort(adj, V);

    return 0;
}
