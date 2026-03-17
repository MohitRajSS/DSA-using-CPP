#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            ans = arr[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            ans = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> arr, int x) {
    int f = findFloor(arr, x);
    int c = findCeil(arr, x);
    return make_pair(f, c);
}

int main() {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;
    pair<int, int> ans = getFloorAndCeil(arr, x);
    cout << "The floor and ceil are: " << ans.first
         << " " << ans.second << endl;
    return 0;
}
