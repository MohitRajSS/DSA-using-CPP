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

Node* point(Node* head1, Node* head2) {
    if (!head1 || !head2) return NULL;

    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != temp2) {
        temp1 = (temp1 == NULL) ? head2 : temp1->next;
        temp2 = (temp2 == NULL) ? head1 : temp2->next;
    }

    return temp1; // Either the intersection node or NULL
}


int main() {
    // Shared part (intersection)
    Node* common = new Node(8);
    common->next = new Node(10);

    // First list: 3 -> 6 -> 9 -> 8 -> 10
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;

    // Second list: 4 -> 8 -> 10 (intersecting at 8)
    Node* head2 = new Node(4);
    head2->next = common;

    Node* intersection = point(head1, head2);

    if (intersection) {
        cout << "Intersection at node with data = " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
