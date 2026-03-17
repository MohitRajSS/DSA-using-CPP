//Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.
#include<iostream>
#include<vector>
using namespace std;

int first(vector<int>nums,int target){
    int n=nums.size();
    int left=0;
    int right=n-1;
    int index=-1;
    while(right>=left){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            index=mid;
            right=mid-1;
        }else if(nums[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return index;
}

int last(vector<int>nums,int target){
    int n=nums.size();
    int left=0;
    int right=n-1;
    int index=-1;
    while(right>=left){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            index=mid;
            left=mid+1;
        }else if(nums[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return index;
}

int numberOfOccurances(vector<int>nums,int target){
    int f=first(nums,target);
    int r=last(nums,target);
    if(f==-1 || r==-1){
        return -1;
    }
    return r-f+1;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int count = numberOfOccurances(nums, target);

    if (count == -1) {
        cout << "Target not found." << endl;
    } else {
        cout << "Number of occurrences of " << target << ": " << count << endl;
    }

    return 0;
}
