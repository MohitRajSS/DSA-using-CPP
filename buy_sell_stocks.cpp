#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int pp(vector<int>prices){
    int maxprofit=0;
    int best_buy=prices[0];
    for(int i=0;i<prices.size();i++){
        if(prices[i]>best_buy){
            maxprofit=max(maxprofit,prices[i]-best_buy);
        }
        best_buy=min(best_buy,prices[i]);
    }
    return maxprofit;
}
int main(){
    vector<int>price={1,2,3,4,5,6,7,8,9,10};
    int k=pp(price);
    cout<<k;
    return k;
}