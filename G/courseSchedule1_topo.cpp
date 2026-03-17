/*Problem Statement I (Course Schedule): There are a total of n tasks you have to pick, labeled from 0 to n-1.
 Some tasks may have prerequisites tasks, for example,
 to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]*/

 #include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isPossible(int V, vector<vector<int>> prerequisites, int m) {
    vector<int> adj[V];
    for (auto it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }

    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
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

    return topo.size() == V;
}

int main() {
    int V = 4;  // Number of tasks
    vector<vector<int>> prerequisites = {
        {1, 0}, 
        {2, 1}, 
        {3, 2}
    };
    int m = prerequisites.size();

    if (isPossible(V, prerequisites, m)) {
        cout << "It is possible to complete all tasks." << endl;
    } else {
        cout << "It is not possible to complete all tasks." << endl;
    }

    return 0;
}
