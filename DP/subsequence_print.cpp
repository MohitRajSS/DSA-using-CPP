#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(vector<int>& arr, int index, vector<int>& current) {
 
    if (index == arr.size()) {
        cout << "{ ";
        for (int i = 0; i < current.size(); ++i) {
            cout << current[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    current.push_back(arr[index]);
    printSubsequences(arr, index + 1, current);

    current.pop_back();
    printSubsequences(arr, index + 1, current);  
}

int main() {
    vector<int> arr = {1, 2, 3}; 
    vector<int> current;
    printSubsequences(arr, 0, current);

    return 0;
}