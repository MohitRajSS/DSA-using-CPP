//Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
#include<iostream>
#include<vector>
using namespace std;

int lB(vector<int>arr,int target){
    int n=arr.size();
    int left=0;
    int right=n-1;
    int index=-1;
    int mid=left+(right-left)/2;
    while(right>=left){
        if(arr[mid]==target){
            index=mid;
            break;
        }else if(arr[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
        mid=left+(right-left)/2;
    }
    if(index!=-1){
        int x=arr[index];
        int i=index;
        while(i>=0 && arr[i]==target){
            i--;
        }
        return i+1;
    }
    return mid;
}

int main() {vector<int> arr2 = {1, 3, 5, 7, 9};
    int target2 = 4;
    int lowerBoundIndex2 = lB(arr2, target2);
    cout << "Lower Bound Index of " << target2 << " in {1, 3, 5, 7, 9} is: " << lowerBoundIndex2 << endl; // Expected: 2 (index of 5)

return 0;
}