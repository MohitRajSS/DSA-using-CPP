#include<iostream>
#include<vector>

int f(int ind,int stock_status,vector<int>&a,int n,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][stock_status]!=-1){
        return dp[ind][stock_status];
    }
    int profit=0;
    if(stock_status){
        profit= max(-a[ind]+f(ind+1,0,a,n,dp),f(ind+1,1,a,n,dp));
    }else{
        profit=max(a[ind]+f(ind+1,1,a,n,dp),f(ind+1,0,a,n,dp));
    }
    return dp[ind][stock_status];
}





int main(){

}