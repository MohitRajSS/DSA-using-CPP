#include<iostream>
#include<vector>
using namespace std;

int minimumIndex(vector<int> nums) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        if (nums[left] <= nums[right]) return left; // Already sorted part

        int mid = left + (right - left) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            return mid; // Found minimum (rotation count)

        if (nums[mid] >= nums[left])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main() {
    vector<int> nums = {2, 4, 5, 6, 7, 0, 1};  // rotated 5 times
    cout << "Rotated " << minimumIndex(nums) << " times\n";
    return 0;
}
