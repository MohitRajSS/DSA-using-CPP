#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads) {
    vector<pair<int, int>> adj[n];

    for (auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, 1e9);
    vector<int> ways(n, 0);

    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        for (auto iter : adj[node]) {
            int adjNode = iter.first;
            int edgeWeight = iter.second;

            if (wt + edgeWeight < dist[adjNode]) {
                dist[adjNode] = wt + edgeWeight;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            } 
            else if (wt + edgeWeight == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]);
            }
        }
    }

    return ways[n - 1];
}

int main() {
    int n = 7;

    vector<vector<int>> edges = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
        {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}
    };

    int ans = countPaths(n, edges);

    cout << ans << endl;

    return 0;
}
