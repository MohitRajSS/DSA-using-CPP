#include<iostream>
#include<vector>
using namespace std;

vector<int>f(vector<int>arr){
    int maxi=-1;
    int sum=0;
    //vector<int>ans;
    int n=arr.size();

    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
        sum+=arr[i];
    }
    return {maxi,sum};
}

int subarraySum(vector<int>arr,int maxSum){
    int subArrays=1;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        if(sum+arr[i]<=maxSum){
            sum=sum+arr[i];
        }else{
            subArrays++;
            sum=arr[i];
        }
    }
    return subArrays;
}

int largestSubarraySumMinimized(vector<int> &a, int k){
    vector<int>re=f(a);
    int low=re[0];
    int high=re[1];
    while(high>=low){
        int mid=low+(high-low)/2;
        int KKK=subarraySum(a,mid);
        if(KKK>k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}


int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}