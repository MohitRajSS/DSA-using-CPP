#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int sum_subsequence(int n,int k,vector<int>&arr){
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=k){
        dp[0][arr[0]]=true;
    }
    for(int i=1;i<n;i++){
        for(int target=0;target<=k;target++){
            bool notTaken=dp[i-1][target];
            bool taken=false;
            if(arr[i]<=target){
                taken=dp[i-1][target-arr[i]];
            }
            dp[i][target]=taken||notTaken;
        }
    }
    return dp[n-1][k];
}

int main(){

vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    if (sum_subsequence(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";


    return 0;
}