#include<iostream>
#include<vector>
using namespace std;

void f(int node,vector<int>adj[],int vis[],vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto i:adj[node]){
        if(!vis[i]){
            f(i,adj,vis,ls);
        }
    }
}

vector<int>dfs(int V,vector<int>adj[]){
    vector<int>ls;
    int vis[V]={0};
    int start=0;
    f(start,adj,vis,ls);
    return ls;
}

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector<int>ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector <int> ans = dfs(5, adj);
    printAns(ans);

    return 0;
}