#include<iostream>
#include<vector>
using namespace std;

struct Node{

    int data;
    Node*next;

    Node(int data1,Node*next1=NULL){
        data=data1;
        next=next1;
    }
};

Node*reverse(Node*head){
    if(head->next==NULL||head==NULL){
        return head;
    }
    Node*newHead=reverse(head->next);
    Node*front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

int main(){
    // Create linked list: 1 -> 2 -> 3
    Node* head = new Node(1, new Node(2, new Node(3)));

    // Reverse the list
    head = reverse(head);

    // Print reversed list
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
