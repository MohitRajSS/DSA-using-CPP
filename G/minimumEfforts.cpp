//You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] 
//represents the height of the cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the 
//bottom-right cell,(rows-1, columns-1) (i.e.,0-indexed). You can move up, down, left, or right, and you wish to find a route that requires
// the minimum effort.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int MinimumEffort(vector<vector<int>>&heights){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>>dis(n,vector<int>(m,1e9));
    dis[0][0]=0;
    pq.push({0,{0,0}});
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int diff=it.first;
        int row=it.second.first;
        int col=it.second.second;
        if(row==n-1 && col==m-1){
            return diff;
        }
        for(int i=0;i<4;i++){
            int newr=row+delrow[i];
            int newc=col+delcol[i];
            if(newr>=0 && newr<n && newc>=0 && newc<m){
                int newEfforts=max(abs(heights[row][col]-heights[newr][newc]) , diff);
                if(newEfforts < dis[newr][newc]){
                    dis[newr][newc]=newEfforts;
                    pq.push({newEfforts,{newr,newc}});
                }
            }
        }
    }
    return 0;
}

int main()
{
    // Driver Code.

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    int ans =MinimumEffort(heights);

    cout << ans;
    cout << endl;

    return 0;
}