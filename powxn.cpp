#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

float powXN(int x,int n){
    if(x==0)return 0;
    if(n==0)return 1;
    if(x==-1 && n%2==0)return 1;
    if(x==-1 && n%2!=0)return -1;
    int binarypow=n;
    double ans=1;
    if(n<0){
        x=1/x;
        binarypow=-n;
    }
    while(binarypow>0){
        if(binarypow%2==1){
            return ans*x;
        }
        binarypow=binarypow/2;
        x=x*x;
    }
    return ans;
}



int main(){
    cout<<powXN(-1,4);
    return 0;
}