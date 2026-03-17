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


Node* add(Node* head) {
    Node* temp = reverse(head);
    Node* current = temp;
    int carry = 1;

    while (current != NULL) {
        current->data += carry;
        if (current->data < 10) {
            carry = 0;
            break;
        } else {
            current->data %= 10;
            carry = 1;
        }
        if (current->next == NULL && carry == 1) {
            current->next = new Node(1);
            carry = 0;
            break;
        }
        current = current->next;
    }

    return reverse(temp);
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Linked list: 1 -> 9 -> 9 => represents number 199
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    Node* result = add(head); // Expected: 2 -> 0 -> 0

    printList(result);
    return 0;
}
