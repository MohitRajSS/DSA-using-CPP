#include<iostream>
#include<vector>
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


int max_path_sum(Node*root,int &max_sum){
    if(root==NULL){
        return 0;
    }
    int lh=max(0,max_path_sum(root->left,max_sum));
    int rh=max(0,max_path_sum(root->right,max_sum));

    max_sum=max(max_sum,lh+rh+root->val);

    return root->val+max(lh,rh);
}

int result(Node*root){
    int max_sum=-1e9;
    max_path_sum (root,max_sum);
    return max_sum;
}

int main(){
    Node*root=new Node(10);
    root->left=new Node(-2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);

    cout<<result(root)<<endl;

    return 0;
}