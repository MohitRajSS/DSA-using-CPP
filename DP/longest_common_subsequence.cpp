#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int f(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
    if(ind1<0 || ind2<0){
        return 0;
    }if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    if(s1[ind1]==s2[ind2]){
        return 1+f(ind1-1,ind2-1,s1,s2,dp);
    }else if(s1[ind1]!=s2[ind2]){
        return 0+max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    }
    return dp[ind1][ind2];
}

int longestCommonSubsequence(string s1,string s2){
    int ind1=s1.size();
    int ind2=s2.size();
    vector<vector<int>>dp(ind1,vector<int>(ind2,-1));
    return f(ind1-1,ind2-1,s1,s2,dp);
}

int main(){
    string s1="mylove";
    string s2="onelove";
    int n=longestCommonSubsequence(s1,s2);
    cout<<n<<endl;
    return 0;
}