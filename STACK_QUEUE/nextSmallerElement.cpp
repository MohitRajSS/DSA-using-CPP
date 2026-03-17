#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=st.top();
        }
        
            st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> result = nextSmallerElement(arr);

    cout << "Next Smaller Elements: ";
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}