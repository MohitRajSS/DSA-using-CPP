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

Node* duplicate(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            Node* temp = current->next;

            if (current == head) {
                head = temp;
                if (head) head->prev = NULL;
            } else {
                current->prev->next = current->next;
                if (current->next) {
                    current->next->prev = current->prev;
                }
            }

            delete current;
            current = temp;
        } else {
            current = current->next;
        }
    }
    return head;
}


int main() {
    // Create list: 1 <-> 2 <-> 3 <-> 2 <-> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Before removing 2s:\n";
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    head = duplicate(head, 2);

    cout << "After removing 2s:\n";
    temp=head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}
