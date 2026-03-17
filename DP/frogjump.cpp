#include<iostream>
#include<vector>
using namespace std;
int frogJump(int n,vector<int> &heights){
    int prev=0;
    int prev2=0;
    for(int i=0;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-2]);
        int ss=0;
        if(i>1) ss=prev2+abs(heights[i],heights[i-2]);
        int curi=min(fs,ss);
        prev2=prev;
        prev=curi;
    }
    return prev;
}