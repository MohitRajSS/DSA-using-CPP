#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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

vector<vector<int>> traversal(Node* root) {
    map<int, map<int, multiset<int>>> nodes; // {x-coordinate -> {y-coordinate -> multiset of node values}}
    queue<pair<Node*, pair<int, int>>> todo; // {node, {x-coordinate, y-coordinate}}
    todo.push({root, {0, 0}});
    
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        
        nodes[x][y].insert(node->val);
        
        if (node->left) {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right) {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }
    
    vector<vector<int>> result;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        result.push_back(col);
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

    vector<vector<int>> result = traversal(root);

    cout << "Vertical Traversal of Tree: " << endl;
    for (const auto& level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
