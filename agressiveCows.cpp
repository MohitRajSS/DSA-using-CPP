#include<stdio.h>
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool ispossible(vector<int>&positions,int mid,int c,int n){
    sort(positions.begin(),positions.end());
    int cows=1;
    int lastStall_pos=positions[0];
    for(int i=1;i<n;i++){
        if(positions[i]-lastStall_pos>=mid){
            cows++;
            lastStall_pos=positions[i];
        }
        if(cows==c){
            return true;
        }
    }
    return false;
}

int sol(vector<int>positions,int c){
    int maximum=-1;
    int minimum=INT_MAX;
    for(int i=0;i<positions.size();i++){
        maximum=max(positions[i],maximum);
        minimum=min(positions[i],minimum);
    }
    int end=maximum-minimum;
    int start=1;
    int ans=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(ispossible(positions,mid,c,positions.size())){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>pr={1,2,3,4,5,6,7,8,9};
    int c=4;
    cout<<sol(pr,c);
}