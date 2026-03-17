#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void postorder(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }
    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);
}

vector<int> preOrder(Node* root) {
    vector<int> arr;
    preorder(root, arr);
    return arr; 
}

vector<int> inOrder(Node* root) {
    vector<int> arr;
    inorder(root, arr);
    return arr;
}

vector<int> postOrder(Node* root) {
    vector<int> arr;
    postorder(root, arr);
    return arr;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result_pre = preOrder(root);
    cout << "Preorder Traversal: ";
    for (int val : result_pre) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result_in = inOrder(root);
    cout << "Inorder Traversal: ";
    for (int val : result_in) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result_post = postOrder(root);
    cout << "Postorder Traversal: ";
    for (int val : result_post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
