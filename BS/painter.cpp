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

int painters(vector<int>arr,int time){
    int n=arr.size();
    int painters=1;
    int sum_time=0;
    for(int i=0;i<n;i++){
        if(sum_time+arr[i] <= time){
            sum_time+=arr[i];
        }else{
            painters++;
            sum_time=arr[i];
        }
    }
    return painters;
}


int findLargestMinDistance(vector<int> &boards, int k){
    vector<int>re=f(boards);
    int low=re[0];
    int high=re[1];
    while(high>=low){
        int mid=low+(high-low)/2;
        int K=painters(boards,mid);
        if(K>k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}