#include<iostream>
#include<vector>
using namespace std;

struct Node{
    Node*next;
    int data;
    Node(int data1,Node*next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
    }
};

int Middle_Node(Node*head){
    Node*slow=head;
    Node*fast=head;

    while(fast!=NULL && slow!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}