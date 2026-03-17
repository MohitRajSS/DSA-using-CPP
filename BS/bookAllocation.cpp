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

int isPossible(vector<int>books,int mid,int st){
    int n=books.size();
    int students=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+books[i] <= mid){
            sum+=books[i];
        }else{
            students++;
            sum=books[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int m){
    vector<int>re=f(arr);
    int low=re[0];
    int high=re[1];
    while(high>=low){
        int mid=low+(high-low)/2;
        int k=isPossible(arr,mid,m);
        if(k>m){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr,m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}