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

struct Node*head=NULL;
int size=0;

void push(int data){
    Node*newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        size++;
        cout<<data<<"Has been pushed"<<endl;
    }else{
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        size++;
        cout<<data<<"Has been pushed"<<endl;
    }
}

void pop(){
    if(head==NULL){
        cout<<"queue is empty"<<endl;
    }else{
        Node*temp=head;
        Node*prev=head;
        temp=temp->next;
        prev->next=NULL;
        cout<<prev->data<<" has been popped"<<endl;
        delete(prev);
        head=temp;
        size--;
    }
}

void  Psize(){
    if(head==NULL){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<"the size of the queue is "<<size<<endl;
    }
}

void peek(){
    if(head==NULL){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<"the topmost element is "<<head->data<<endl;
    }
}

void isEmpty(){
    if(head==NULL){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<"queue is not empty"<<endl;
    }
}

void printQueue(){
    if(head==NULL){
        cout<<"queue is empty"<<endl;
    }else{
    Node*temp=head;
    cout<<"<--";
    while(temp!=NULL){
        cout<<temp->data;
        cout<<"--";
        temp=temp->next;
    }
    cout<<"<--";
    }
}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    cout<<endl;
    cout<<endl;

    printQueue();
    Psize();
    peek();
    isEmpty();

    cout<<endl;
    cout<<endl;

    pop();
    pop();
    pop();

    printQueue();
    Psize();
    peek();
    isEmpty();

    cout<<endl;
    cout<<endl;

    return 0;
}