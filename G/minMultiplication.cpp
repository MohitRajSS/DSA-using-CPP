//Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation 
//with 100000 is done to get the new start.Your task is to find the minimum steps in which the end can be achieved starting from the start.
// If it is not possible to reach the end, then return -1.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minimumMultiplications(vector<int>&arr,int start,int end){
    queue<pair<int,int>>q;
    q.push({start,0});

    vector<int>dist(100000,1e9);
    dist[start]=0;
    int mod=100000;

    while(!q.empty()){
        int node=q.front().first;
        int steps=q.front().second;
        q.pop();
        for(auto it:arr){
            int num=(it*node)%mod;
            if(steps+1<dist[num]){
                dist[num]=1+steps;
            }
            if(num==end){
                return steps+1;
            }
            q.push({num,steps+1});
        }
    }
    return -1;
}
int main()
{
    int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};


    int ans =minimumMultiplications(arr, start, end);

    cout << ans;
    cout << endl;

    return 0;
}