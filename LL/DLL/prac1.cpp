#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node*prev;
    Node*next;

    Node(int data1,Node*next1,Node*prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int data1){
        data=data1;
        next=NULL;
        prev=NULL;
    }
};

Node* convertArrToLL(vector<int>p){
    Node*head=new Node(p[0]);
    Node*previous=head;
    for(int i=1;i<p.size();i++){
        Node*newNode=new Node(p[i]);
        previous->next=newNode;
        newNode->prev=previous;
        previous=newNode;
    }

    Node*temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    while(temp->prev!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<temp->data;
    return head;
}

Node* insertAtHead(Node*head,int data){
    Node*newNode=new Node(data);
    if(head==NULL){
        head=newNode;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;

    Node*temp=head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return head;
}

Node*insertAtTail(Node*head,int data){
     Node*newNode=new Node(data);
    if(head==NULL){
        return newNode;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
    temp=head;
    cout<<endl;
    while(temp!=NULL){
        
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return head;
}

Node*insertAtPos(Node*head,int data,int pos){
    if(pos==1){
        return insertAtHead(head,data);
    }
    int cnt=1;
    Node*temp=head;
    while(temp!=NULL && cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL||temp==NULL){
        return insertAtTail(head ,data);
    }
    Node*newNode=new Node(data);
    newNode->next=temp->next;
    temp->next->prev=newNode;
    newNode->prev=temp;
    temp->next=newNode;

    temp=head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return head;
}
int main() {
    vector<int> ans = {1, 2, 3, 4, 5};
    Node* head = convertArrToLL(ans);
    //printForward(head);

    head = insertAtHead(head, 0); // Insert 0 at the beginning
    //printForward(head);
    head=insertAtTail(head,6);
    head=insertAtPos(head,56,7);
    return 0;
}