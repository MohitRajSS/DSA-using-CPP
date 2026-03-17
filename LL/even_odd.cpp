#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};

Node* result(Node* head) {
    if (head == NULL) return NULL;

    Node* odd = head;
    Node* even = head;

    while (odd != NULL && odd->data % 2 != 0) {
        odd = odd->next;
    }

    while (even != NULL && even->data % 2 == 0) {
        even = even->next;
    }

    if (!odd && !even) return NULL;

    Node* temp;
    Node* oddHead = odd;
    Node* evenHead = even;

    if (odd) {
        temp = odd->next;
        while (temp != NULL) {
            if (temp->data % 2 != 0) {
                odd->next = temp;
                odd = temp;
            }
            temp = temp->next;
        }
        odd->next = NULL;
    }

    if (even) {
        temp = even->next;
        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                even->next = temp;
                even = temp;
            }
            temp = temp->next;
        }
        even->next = NULL;
    }

    if (even) {
        even->next = oddHead;
        return evenHead;
    } else {
        return oddHead;
    }
}

Node*odd_place_even_place(Node*head){
    Node*oddHead=new Node(-1);
    Node*evenHead=new Node(-1);
    Node*oddTail=oddHead;
    Node*evenTail=evenHead;
    Node*temp=head;
    Node*current=head;
    while(current!=NULL){
        temp=current;
        current=current->next;
        temp->next=NULL;
        if(temp->data%2!=0){
            oddTail->next=temp;
            oddTail=temp;
        }else{
            evenTail->next=temp;
            evenTail=temp;
        }
    }
    evenTail->next=oddHead->next;
    return evenHead->next;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    Node* res = odd_place_even_place(head);
    while (res != NULL) {
        cout << res->data << " ";
        res = res->next;
    }
    return 0;
}
