#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& A, int tar) {
    int st = 0, end = A.size() - 1; 
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (A[mid] == tar) {
            return mid;
        }
        if (A[st] <= A[mid]) {
            if (A[st] <= tar && tar <= A[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        } else {
            if (A[mid] <= tar && tar <= A[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> price = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10, 95, 105, 125, 1993};
    int k = search(price, 125); 
    cout << "Element found at index: " << k << endl;
    return 0;
}
