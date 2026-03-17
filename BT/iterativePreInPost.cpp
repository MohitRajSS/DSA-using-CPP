#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> iterativePreorder(TreeNode* root) {
    vector<int> preorder;
    if (root == nullptr) return preorder;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        preorder.push_back(node->data);

        if (node->right != nullptr) st.push(node->right);
        if (node->left != nullptr) st.push(node->left);
    }

    return preorder;
}

vector<int> iterativeInorder(TreeNode* root) {
    vector<int> inorder;
    stack<TreeNode*> st;
    TreeNode* node = root;

    while (true) {
        if (node != nullptr) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty()) break;
            node = st.top(); st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }

    return inorder;
}

vector<int> iterativePostorder(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* node = st1.top(); st1.pop();
        st2.push(node);

        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    while (!st2.empty()) {
        ans.push_back(st2.top()->data);
        st2.pop();
    }

    return ans;
}

int main() {
    // Sample tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int> pre = iterativePreorder(root);
    vector<int> in = iterativeInorder(root);
    vector<int> post = iterativePostorder(root);

    cout << "Preorder: ";
    for (int val : pre) cout << val << " ";
    cout << "\nInorder: ";
    for (int val : in) cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : post) cout << val << " ";
    cout << endl;

    return 0;
}
