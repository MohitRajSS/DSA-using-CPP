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

bool checkPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp1 = reverse(slow);
    Node* temp2 = head;
    Node* copy = temp1; 
    while (temp1 != NULL) {
        if (temp1->data != temp2->data) {
            reverse(copy);
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    reverse(copy);
    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    bool k=checkPalindrome(head);
    if (k) {
        cout << "The linked make a palindrome" <<  endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}

