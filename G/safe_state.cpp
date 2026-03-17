#include<iostream>
#include<vector>

bool dfs(int node,vector<int>adj[],int vis[],int pathvis[],int check[]){
    vis[node]=1;
    pathvis[node]=1;
    check[node]=0;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathvis,check)){
                check[node]=0;
                return true;
            }
        }else if(pathVis[it]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
}

vector<int>evaluate(int V,vector<int>adj[]){
    int vis[V]={0};
    int pathvis[V]={0};
    int check[V]={0};
    vector<int>safeNodes;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,pathvis,check);
        }
    }
    for(int i=0;i<V;i++){
        if(check[i]==1){
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}



int main(){


    return 0;
}