#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                vis[i][j]=1;
                q.push({{i,j},0});
            }else{
                vis[i][j]=0;
            }
        }
    }
    
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dis[row][col]=steps;
        for(int i=0;i<4;i++){
            int rrow=row+delrow[i];
            int rcol=col+delcol[i];
            if(rrow>=0 && rrow<n && rcol>=0 && rcol<m && vis[rrow][rcol]==0){
                vis[rrow][rcol]=1;
                q.push({{rrow,rcol},steps+1});
            }
        }
    }
    return dis;
}
int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	vector<vector<int>> ans =nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}