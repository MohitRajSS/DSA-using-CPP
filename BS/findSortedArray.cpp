#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>arr,int target){
    int n=arr.size();
    int left=0;
    int right=n-1;

    int index=-1;
    while(right>=left){
        int mid=left+(-left+right)/2;
        if(target>arr[mid]){
            left=mid+1;
        }else if(target<arr[mid]){
            right=mid-1;
        }else{
            index=mid;
            break;
        }
    }
    return index;
}

int recursiveFind(vector<int>arr,int target,int left,int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(arr[mid]>target){
        right=mid-1;
        return recursiveFind(arr,target,left,right);
    }else if(arr[mid]<target){
        left=mid+1;
        return recursiveFind(arr,target,left,right);
    }else{
        return mid;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int target = 5;
    int idx = recursiveFind(arr, target,0,arr.size()-1);

    if (idx != -1)
        cout << "Element found at index: " << idx << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}