#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(vector<int> adj[], int N) {
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topoSort;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    return topoSort;
}

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int l = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < l; ptr++) {
            if (s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(adj, K);
    string ans = "";
    for (int i = 0; i < topo.size(); i++) {
        ans += char(topo[i] + 'a');
    }
    return ans;
}

int main() {
    string dict[] = {"caa", "aaa", "aab"};
    int N = 3, K = 3;
    cout << "Order of characters: " << findOrder(dict, N, K) << endl;
    return 0;
}
