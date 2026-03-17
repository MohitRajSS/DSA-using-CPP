#include<iostream>
#include<vector>
using namespace std;

int kthElement(vector<int> nums1, vector<int> nums2, int k) {
    int i = 0, j = 0, cnt = 0;
    int n1 = nums1.size(), n2 = nums2.size();

    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            if (cnt == k) return nums1[i];
            cnt++;
            i++;
        } else {
            if (cnt == k) return nums2[j];
            cnt++;
            j++;
        }
    }

    while (i < n1) {
        if (cnt == k) return nums1[i];
        cnt++;
        i++;
    }

    while (j < n2) {
        if (cnt == k) return nums2[j];
        cnt++;
        j++;
    }

    return -1; // if k is out of bounds
}

int main()
            {
                vector<int> a = {2, 3, 6, 7, 9};
                vector<int> b = {1, 4, 8, 10};
                cout << "The k-ht element of two sorted array is: " <<
                        kthElement(a, b, 5) << '\n';
            }