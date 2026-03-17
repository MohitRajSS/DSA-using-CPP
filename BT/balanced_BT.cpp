#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int data){
        this->left=NULL;
        this->right=NULL;
        val=data;
    }
};

// int isBalanced(Node*root){
//     return dfsHeight(root)!=-1;
// }

int dfsHeight(Node*root){
    if(root==NULL){
        return 0;
    }
    int left=dfsHeight(root->left);
    int right=dfsHeight(root->right);
    if(left==-1||right==-1){
        return -1;
    }
    if(abs(left-right)>1){
        return -1;
    }
    return max(left,right)+1;
}

int isBalanced(Node*root){
    return dfsHeight(root)!=-1;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    if(isBalanced(root)){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"notBalanced"<<endl;
    }
    return 0;
}