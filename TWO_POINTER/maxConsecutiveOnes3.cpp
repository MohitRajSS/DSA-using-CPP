#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int zeros=0;
        int max_length=0;
        while(r<n){
            if(nums[r]==0)zeros++;
            if(zeros>k){
                if(nums[l]==0)zeros--;
                l++;
            }
            max_length=max(max_length,r-l+1);
            r++;
        }
        return max_length;
    }
};

int main(){

    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    Solution sol;
    int k=sol.longestOnes(arr,2);
    cout<<k<<endl;
    return 0;
}