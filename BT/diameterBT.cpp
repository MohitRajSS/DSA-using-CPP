#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int data) {
        left = NULL;
        right = NULL;
        val = data;
    }
};

int diameter(Node* node, int& maxi) {
    if (node == NULL) {
        return 0;
    }

    int lh = diameter(node->left, maxi);
    int rh = diameter(node->right, maxi);

    maxi = max(maxi, lh + rh);

    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int maxi = 0;
    diameter(root, maxi);

    cout << "Diameter of the tree: " << maxi << endl;

    return 0;
}