#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> preOrder(Node* root) {
    vector<int> preorder;
    if (root == NULL) return preorder;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* node = st.top();
        st.pop();
        preorder.push_back(node->val);
        if (node->right != NULL) {
            st.push(node->right);
        }
        if (node->left != NULL) {
            st.push(node->left); // Corrected this line
        }
    }
    return preorder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = preOrder(root);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}