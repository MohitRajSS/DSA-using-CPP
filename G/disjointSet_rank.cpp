#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }

        void unionByRank(int u,int v){
            int ultimate_parent_u=findParent(u);
            int ultimate_parent_v=findParent(v);
            if(ultimate_parent_u==ultimate_parent_v)return;

            if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
                parent[ultimate_parent_u]=ultimate_parent_v;
            }
            else if(rank[ultimate_parent_u]>rank[ultimate_parent_v]){
                parent[ultimate_parent_v]=ultimate_parent_u;
            }else{
                parent[ultimate_parent_v]=ultimate_parent_u;
                rank[ultimate_parent_u]++;
            }
        }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}