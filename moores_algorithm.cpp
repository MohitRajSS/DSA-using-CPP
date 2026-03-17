#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int majorityElement(vector<int> nums){
    int freq=0;
    int element=0;
    for(int i=0;i<nums.size();i++){
        if(freq==0){
            element=nums[i];
        }if(element==nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    freq=0;
    for(int i=0;i<nums.size();i++){
        if(element==nums[i]){
            freq++;
        }
    }
    if(freq<(nums.size())/2){
        return -1;
    }
    return element;
}

int main() {
    vector<int> nums = {-2, -3, -3, -2, -1,-3, -3, -3};
    int ans = majorityElement(nums);
    cout<<ans;
    return 0;
}