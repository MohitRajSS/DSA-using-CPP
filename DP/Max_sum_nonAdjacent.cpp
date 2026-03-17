#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
// Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

int max_sum(int n,vector<int>&arr){
    vector<int>dp(n,0);
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        int pick=arr[i];
        if(i>1){
            pick+=dp[i-2];
        }
        int notpick=dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[n-1];
}



int main(){

}