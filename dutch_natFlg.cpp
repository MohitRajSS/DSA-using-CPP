#include<iostream>
#include<vector>
using namespace std;

void Colorsort(vector<int>& arr) {
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

int main() {
    vector<int> hello = {0, 1, 2, 2, 1, 0};
    Colorsort(hello);
    for (int i = 0; i < hello.size(); i++) {
        cout << hello[i] << " "; 
    }
    
    return 0;
}