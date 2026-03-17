#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int maximum(vector<int> arr) {
        int maxi = -1;
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    int isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();
        int cnt = 0;
        int flowers = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    cnt++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        if (cnt >= m) {
            return 1;
        } else {
            return 2;
        }
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = 1;
        int high = maximum(bloomDay);
        int ans = INT_MAX;

        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, m, k, mid) == 1) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum day to make " << m << " bouquets of " << k << " flowers: " << result << endl;

    return 0;
}
