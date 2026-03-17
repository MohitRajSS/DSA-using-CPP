#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 //Subarray With K Different Integers

 int help(vector<int>arr,int k){
    if(k<0){
        return 0;
    }
    int l=0;
    int r=0;
    int n=arr.size();
    int cnt=0;
    unordered_map<int,int>mpp;
    while(r<n){
        mpp[arr[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        cnt=cnt+r-l+1;
        r++;
    }
    return cnt;
 }

 int func(vector<int>&arr,int k){
    return help(arr,k)-help(arr,k-1);
 }

 int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    cout << func(arr, k) << endl;  // Output should be 7
    return 0;
}
