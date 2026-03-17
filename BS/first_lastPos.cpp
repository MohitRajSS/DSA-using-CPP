//Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.
#include<iostream>
#include<vector>
using namespace std;

int firstOccurance(vector<int>nums,int target){
    int n=nums.size();
    int left=0;
    int right=n-1;
    int index=-1;
    while(right>=left){
        int mid=(left+right)/2;
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

int lastOccurance(vector<int>nums,int target){
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

vector<int> searchRange(vector<int>& nums, int target){
    vector<int>ans;
    int f=firstOccurance(nums,target);
    ans.push_back(f);
    int l=lastOccurance(nums,target);
    ans.push_back(l);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4};
    int target = 2;

    vector<int> result = searchRange(nums, target);
    cout << "First and Last Occurrence of " << target << ": "
         << result[0] << " " << result[1] << endl;

    return 0;
}