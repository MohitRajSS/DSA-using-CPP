#include<stdio.h>
#include<iostream>
#include<vector>

int f(int idx,int W,vector<int>&weight,vector<int>&val){
    if(idx==0){
        if(weight[0]==W){
            return val[0];
        }else{
            return 0;
        }
    }
    int notTaken=0+f(idx-1,W,weight,val);
    int taken=INT_MIN;
    if(weight[idx]<=W){
        taken=val[idx]+f(idx-1,W-weight[idx],weight,val);
    }
    return max(notTaken,taken);
}







int main(){



    return ;
}