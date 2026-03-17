#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> f(vector<int>& arr) {
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 6, 4};
    vector<int> res = f(arr);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
