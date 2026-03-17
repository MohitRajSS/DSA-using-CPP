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

struct Node* head = NULL;
int size=0;

void push(int data){
    Node*newNode=new Node(data);
    if(head==NULL){
        head=newNode;
    }else{
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    cout<<data<<" Has been pushed"<<endl;
    size++;
}

void pop(){
    if(head==NULL){
        cout<<"the stack is empty"<<endl;
    }else{
        Node*temp=head;
        Node*prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        cout<<temp->data<<" has been popped"<<endl;
        prev->next=NULL;
        delete(temp);
        size--;
    }
}

void peek(){
    if(head==NULL){
        cout<<"the stack is empty"<<endl;
    }else{
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        cout<<temp->data<<" is the top element"<<endl;
    }
}

void isEmpty(){
    if(head==NULL){
        cout<<"the stack is empty"<<endl;
    }else{
        cout<<"the stack is not empty"<<endl;
    }
}

void Psize(){
    if(head==NULL){
        cout<<"the stack is empty hence the size is 0"<<endl;
    }else{
        cout<<size<<endl;
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    peek();

    pop();
    pop();
    pop();

    peek();

    Psize();
    isEmpty();
    return 0;
}