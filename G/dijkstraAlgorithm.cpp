// Dijkstra's Algorithm using Min-Heap (Priority Queue)
#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist_node(V, 1e9);
    dist_node[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int nd = it[0];  
            int wt = it[1];  

            if (dist + wt < dist_node[nd]) {
                dist_node[nd] = dist + wt;
                pq.push({dist_node[nd], nd});
            }
        }
    }
    return dist_node;
}

int main() {
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];

    // Graph edges: {destination, weight}
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
