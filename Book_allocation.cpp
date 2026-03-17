#include<stdio.h>
#include<iostream>
#include<vector>

bool isValid(vector<int>&arr,int n,int m,int max_allowed){
    int students=1;
    int pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max_allowed){
            return false; 
        }
        if(pages[i]+arr[i]<=max_allowed){
            pages+=arr[i];
        }else{
            students++;
            pages=arr[i];
        }
    }
    return students > m ? false : true;
}


int allocateBooks(vector<int> &arr,int n,int m){
    if(m>n){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int ans=-1;
    int start=0 end=sum;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}



int main(){
    
    return 0;
}