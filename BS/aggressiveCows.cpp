#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(vector<int>arr,int dist,int cows){
    int cnt=1;
    int last=arr[0];
    int n=arr.size();

    for(int i=1;i<n;i++){
        if(arr[i]-last >= dist){
            cnt++;
            last=arr[i];
        }
        if(cnt==cows)return true;
    }
    return false;
}

int f(vector<int>stalls,int k){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[n-1]-stalls[0];

    while(high>=low){
        int mid=low+(high-low)/2;
        if(canPlace(stalls,mid,k)==true){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << f(stalls, cows) << endl; // Output should be 3
    return 0;
}