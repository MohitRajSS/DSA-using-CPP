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

Node*merge_twoSortedLL(Node*head1,Node*head2){
    Node*resultHead=new Node(-1);
    Node*resultTail=resultHead;

    Node*temp1=head1;
    Node*temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data > temp2->data){
            resultTail->next=temp2;
            resultTail=temp2;
            temp2=temp2->next;
            resultTail->next=NULL;
        }else{
            resultTail->next=temp1;
            resultTail=temp1;
            temp1=temp1->next;
            resultTail->next=NULL;
        }
    }
    if(temp1){
        resultTail->next=temp1;
    }if(temp2){
        resultTail->next=temp2;
    }
    return resultHead->next;
}

int main(){
    Node*head1=new Node(1);
    head1->next=new Node(2);
    head1->next->next=new Node(4);
    head1->next->next->next=new Node(6);
    Node*head2=new Node(1);
    head2->next=new Node(3);
    head2->next->next=new Node(5);
    head2->next->next->next=new Node(7);

    Node*result=merge_twoSortedLL(head1,head2);

    Node*temp1=result;
    while(temp1!= NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    return 0;
}