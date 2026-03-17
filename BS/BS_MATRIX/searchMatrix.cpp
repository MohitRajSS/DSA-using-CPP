#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n * m - 1);
        while (high >= low) {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            int k = matrix[row][col];
            if (k == target) {
                return true;
            } else if (k > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 16;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix.\n";
    } else {
        cout << "Target " << target << " not found in the matrix.\n";
    }

    return 0;
}
