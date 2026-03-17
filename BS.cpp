#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int BS_iterative(vector<int> arr, int target) {
    int i = 0;
    int j = arr.size() - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2; // Avoid overflow
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return -1;
}


int BS_recursive(vector<int> arr, int first, int last, int target) {
    if (first > last) {
        return -1;
    }
    int mid = first + (last - first) / 2; 

    if (arr[mid] == target) {
        return mid;  
    } else if (arr[mid] > target) {
        return BS_recursive(arr, first, mid - 1, target);  
    } else {
        return BS_recursive(arr, mid + 1, last, target);
    }
}

int main(){
    vector<int>price={1,2,3,4,5,5,6,7,8,9,10,95,105,125,1993};
    int k=BS_iterative(price,125);
    int l=BS_recursive(price,0,price.size()-1,125);
    cout<<k<<endl;
    cout<<l;
    return 0;
}