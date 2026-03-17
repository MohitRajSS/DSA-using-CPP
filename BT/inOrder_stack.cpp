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

vector<int>inorder(Node*root){
    vector<int>inorder;
    stack<Node*>st;
    Node*node=root;

    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()){
                break;
            }else{
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
    }
    return inorder;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    vector<int>result=inorder(root);
    for(int num:result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}