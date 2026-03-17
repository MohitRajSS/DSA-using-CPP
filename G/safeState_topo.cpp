#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> safeNodes(vector<int> adj[], int V) {
    vector<int> revAdj[V];
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            revAdj[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safeNodes;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for (auto it : revAdj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main() {
    int V = 7; 
    vector<int> adj[V];

    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {5};
    adj[3] = {0, 4};
    adj[4] = {5};
    adj[5] = {};
    adj[6] = {3, 4};

    vector<int> result = safeNodes(adj, V);

    cout << "Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
