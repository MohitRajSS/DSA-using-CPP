#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> arr, int target) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int ans = n;

    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1; // ✅ FIXED!
        }
    }
    return ans;
}


int main() {
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int target = 10;
    cout << "Upper Bound Index of " << target << " is: " << f(arr, target) << endl;
    return 0;
}