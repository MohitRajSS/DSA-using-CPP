#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int cheapestFlight(int n,vector<vector<int>>&flights,int src,int dst,int k){
    vector<pair<int,int>>adj[n];
    for(auto it :flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    vector<int>dist(n,1e9);
    dist[src]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int count=it.first;
        int node=it.second.first;
        int wt=it.second.second;
        if(count>k) continue;
        for(auto iter:adj[node]){
            int adjNode=iter.first;
            int adjWt=iter.second;
            if(adjWt+wt<dist[adjNode] && count<=k){
                dist[adjNode]=adjWt+wt;
                q.push({count+1,{adjNode,adjWt+wt}});
            }
        }
    }



    if(dist[dst]==1e9) return -1;
    return dist[dst];
}

    int main() {
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 2, 500}};
    int src = 0, dst = 3, k = 1;

    cout << "Cheapest flight cost: " << cheapestFlight(n, flights, src, dst, k) << endl;
    return 0;
}
 