#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximum(vector<int> arr){
        int maxi = -1;
        for(int i = 0; i < arr.size(); i++){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    int result(vector<int>& nums, int k){
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % k == 0){
                cnt += nums[i] / k;
            } else {
                cnt += nums[i] / k + 1;
            }
        }
        return cnt;
    }

    int smallestDivisor(vector<int>& nums, int threshold){
        int low = 1;
        int high = maximum(nums);
        int ans = -1;

        while(high >= low){
            int mid = low + (high - low) / 2;
            if(result(nums, mid) <= threshold){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int answer = sol.smallestDivisor(nums, threshold);
    cout << "Smallest divisor is: " << answer << endl;

    return 0;
}
