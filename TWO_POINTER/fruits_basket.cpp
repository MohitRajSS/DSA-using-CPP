#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int f(vector<int>arr){
    int l=0;
    int r=0;
    int max_len=0;
    unordered_map<int,int>mpp;
    while(r<arr.size()){
        mpp[arr[r]]++;
        if(mpp.size()>2){
            while(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        max_len=max(max_len,r-l+1);
        r++;
    }
    return max_len;
}


int main(){
    vector<int>arr={3,3,3,1,2,1,1,2,3,3,4};
    cout<<f(arr)<<endl;
    return 0;
}