#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> PreInPost(TreeNode* root) {
    vector<vector<int>> result(3); // Pre, In, Post

    if (root == NULL) return result;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1) {
            result[0].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != nullptr) {
                st.push({it.first->left, 1});
            }
        }
        // Inorder
        else if (it.second == 2) {
            result[1].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != nullptr) {
                st.push({it.first->right, 1});
            }
        }
        // Postorder
        else {
            result[2].push_back(it.first->data);
        }
    }
    return result;
}

int main() {
    // Sample tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> res = PreInPost(root);

    cout << "Preorder: ";
    for (int x : res[0]) cout << x << " ";
    cout << "\nInorder: ";
    for (int x : res[1]) cout << x << " ";
    cout << "\nPostorder: ";
    for (int x : res[2]) cout << x << " ";
    cout << endl;

    return 0;
}
