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

void preInPostTraversal(Node* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
    if (root == NULL) return;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            inorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
            postorder.push_back(it.first->val);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> preorder, inorder, postorder;
    preInPostTraversal(root, preorder, inorder, postorder);

    cout << "Preorder: ";
    for (int num : preorder) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Inorder: ";
    for (int num : inorder) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int num : postorder) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}