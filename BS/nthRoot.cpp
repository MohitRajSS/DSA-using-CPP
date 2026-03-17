#include<iostream>
#include<vector>
using namespace std;

int func(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m){
            return 2;
        }
    }
    if(ans==m)return 1;
    return 0;
}

int f(int n,int m){
    int low=0;
    int high=m;
    while(high>=low){
        int mid=high+(low-high)/2;
        if(func(mid,n,m)==2){
            high=mid-1;
        }else if(func(mid,n,m)==1){
            return mid;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = f(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}