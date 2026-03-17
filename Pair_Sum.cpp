#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> pairSum(vector<int> nums, int target) {
    vector<int> ans;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        } else {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;
    vector<int> ans = pairSum(nums, target);
    
    if (!ans.empty()) {
        cout << ans[0] << "," << ans[1] << endl;
    } else {
        cout << "No valid pair found" << endl;
    }
    
    return 0;
}
