#include<iostream>
#include<vector>
using namespace std;
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(right>=left){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target && nums[mid]>=target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(nums[mid]<=target && nums[right]>=target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // rotated sorted array
    int target = 0;

    int index = search(nums, target);

    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
