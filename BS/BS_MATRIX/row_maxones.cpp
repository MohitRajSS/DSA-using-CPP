#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> arr,int m){
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    while(high>=low){
        int mid=(low+(high-low)/2);
        if(arr[mid]==0){
            low=mid+1;
        }else{
            high=mid-1;
            ans=mid;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
    int cnt_max=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int x=m-f(matrix[i],m);
        if(x>cnt_max){
            cnt_max=x;
            index=i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix,n, m) << '\n';
}