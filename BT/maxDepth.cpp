#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int data){
        left=NULL;
        right=NULL;
        val=data;
    }
};

int maxDepth(Node*root){
    if(root==NULL){
        return 0;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return 1+max(left,right);
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<maxDepth(root)<<endl;
    return 0;
}