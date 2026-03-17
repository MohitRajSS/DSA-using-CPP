#include<iostream>
#include<vector>
#include<stack>
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

vector<int>postorderTraversal(Node*root){
    vector<int>postorder;
    if(root==NULL){
        return postorder;
    }
    stack<Node*>st1,st2;
    st1.push(root);

    while(!st1.empty()){
         Node*node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=NULL){
                st1.push(node->left);
            }
            if(node->right!=NULL){
                st1.push(node->right);
        }
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    vector<int>result=postorderTraversal(root);
    for(int num:result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
