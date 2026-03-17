#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node*next;

    Node(int data1, Node*next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

int length(Node*head){
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int isPresent(Node*head,int target){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int main(){
    vector<int> arr = {12, 8, 5, 7, 8};  // You missed this line

    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next=new Node(arr[4]);
    cout << "length of Linked List: "<<length(head)<<endl;
    cout<<isPresent(head,70);
    return 0;
}