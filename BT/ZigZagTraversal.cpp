#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> zigzaglevelorder(Node* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }
    queue<Node*> q;
    q.push(root);
    int flag = 1;
    while (!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            int index = (flag == 1) ? i : size - i - 1;
            row[index] = current->val;
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        flag = 1 - flag;
        result.push_back(row);
    }
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = zigzaglevelorder(root);

    cout << "Zigzag Level Order Traversal of Tree: " << endl;
    for (const auto& level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}