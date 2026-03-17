#include<vector>
#include<iostream>
using namespace std;

//MAX POINTS YOU CAN OBTAIN FROM CARDS
int f(vector<int>&arr,int k){
    int n=arr.size();
    int left_sum=0;
    int right_sum=0;
    int max_sum=0;
    for(int i=0;i<k;i++){
        left_sum=left_sum+arr[i];
    }
    max_sum=left_sum;
    int rightIndex=n-1;
    for(int i=k-1;i>=0;i--){
        right_sum=right_sum+arr[rightIndex];
        rightIndex--;
        left_sum=left_sum-arr[i];
        max_sum=max(left_sum+right_sum,max_sum);
    }
    return max_sum;
}

int main(){
    vector<int>ans={1,2,3,4,5};
    int k=3;
    cout<<"max sum with constrain k"<<f(ans,k)<<endl;
    return 0;
}