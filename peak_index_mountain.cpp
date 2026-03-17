#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int peakIndex(vector<int> arr) {
        int start=0;
        int end =arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid-1]<arr[mid]){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return -1;
    }

int main()
{
    vector<int>ans={1,2,3,4,5,5,4,3,2,1};
    int k=peakIndex(ans);
    cout<<k;
    return 0;
}