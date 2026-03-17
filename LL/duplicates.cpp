#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
    Node(int data1,Node*next1=NULL,Node*prev1=NULL){
        data=data1;
        next=next1;
        prev=prev1;
    }
};

    Node*removeDuplicate(Node*head){
        Node*temp=head;
        while(temp->next!=NULL){
            if(temp->data==temp->next->data){
                if(temp==head){
                    head=temp->next;
                    delete(temp);
                    temp=head;
                    continue;
                }
                Node*temp1=temp->next;
                temp->prev->next=temp1;
                temp1->prev=temp->prev;
                temp->next=NULL;
                temp->prev=NULL;
                delete(temp);
                temp=temp1;
                continue;
            }
            temp=temp->next;
        }
        return head;
    }

int main() {
    // Create sorted doubly linked list with duplicates
    Node* head = new Node(1);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(2, nullptr, head->next);
    head->next->next->next = new Node(3, nullptr, head->next->next);
    head->next->next->next->next = new Node(4, nullptr, head->next->next->next);
    head->next->next->next->next->next = new Node(4, nullptr, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(5, nullptr, head->next->next->next->next->next);

    cout << "Before removing duplicates:\n";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = removeDuplicate(head);

    cout << "After removing duplicates:\n";
    temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
