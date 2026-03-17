#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    Node*left;
    Node*right;
    int val;
    Node(int data){
        left=NULL;
        right=NULL;
        val=data;
    }
};

bool isLeaf(Node*node){
    if(node->left==NULL && node->right==NULL){
        return true;
    }
    return false;
}

void leftBoundary(Node*root,vector<int>&result){
    Node*current=root->left;
    while(current){
        if(!isLeaf(current)){
            result.push_back(current->val);
        }
        if(current->left!=NULL){
            current=current->left;
        }else{
            current=current->right;
        }
    }
}

void rightBoundary(Node*root,vector<int>&result){
    struct Node*current=root->right;
    vector<int>temp;
    while(current){
        if(!isLeaf(current)){
            temp.push_back(current->val);
        }
        if(current->right!=NULL){
            current=current->right;
        }else{
            current=current->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        result.push_back(temp[i]);
    }
}

void leaf(Node*root,vector<int>&result){
    if(isLeaf(root)){
        result.push_back(root->val);
        return;
    }
    if(root->left){
        leaf(root->left,result);
    }
    if(root->right){
        leaf(root->right,result);
    }
}

vector<int> printBoundary(Node*root){
    vector<int>result;
    if(root==NULL){
        return result;
    }
    if(!isLeaf(root)){
        result.push_back(root->val);
    }
    leftBoundary(root,result);
    leaf(root,result);
    rightBoundary(root,result);
    return result;
}

void printResult(vector<int>&result){
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //Solution solution;

    // Get the boundary traversal
    vector<int> result = printBoundary(root);

    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}