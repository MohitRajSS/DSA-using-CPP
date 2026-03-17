#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int maxwater(vector<int>height){
    int i=0;
    int j=height.size()-1;
    int max_water=0;
    while(i<j){
        int current_height=(j-i)*min(height[i],height[j]);
        max_water=max(max_water,current_height);
        if(height[i]>height[j]){
            j--;
        }else{
            i++;
        }
    }
    return max_water;
}




int main(){
    vector<int>pp={1,8,6,2,5,4,8,3,7};
    cout<<maxwater(pp);
    return 0;
}