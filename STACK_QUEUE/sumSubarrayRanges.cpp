#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>fp(vector<int>&arr){
    int n=arr.size();
    vector<int>pse(n);
    stack<int>st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]> arr[i]){
            st.pop();
        }
        pse[i]=st.empty() ? -1:st.top();
        st.push(i);
    }
    return pse;
}

vector<int>fn(vector<int>&arr){
    int n=arr.size();
    vector<int>nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        nse[i]=st.empty()? n:st.top();
        st.push(i);
    }
    return nse;
}

int sumSubarrayMins(vector<int>&arr){
    int n=arr.size();
    vector<int>pse=fp(arr);
    vector<int>nse=fn(arr);
    int total=0;
    for(int i=0;i<n;i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        total+=arr[i]*left*right;
    }
    return total;
}

vector<int>fpg(vector<int>arr){
    int n=arr.size();
    vector<int>pge(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        pge[i]=st.empty()? -1:st.top();
        st.push(i);
    }
    return pge;
}

vector<int>fng(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nge(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        nge[i]=st.empty()? n:st.top();
        st.push(i);
    }
    return nge;
}

    int sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge = fpg(arr);
        vector<int> nge = fng(arr);
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total = (total + (arr[i] * left % mod * right % mod) % mod) % mod;
        }
        return total;
    }

int subArrayRanges(vector<int>& nums) {
        int ans=1LL *sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    return ans;
}

int main() {
vector<int> nums = {1, 2, 3};
    cout << subArrayRanges(nums) << endl;

    return 0;
}
