#include<iostream>
#include<vector>
using namespace std;

struct Node {
    Node* next;
    int data;
    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};

Node* sort_zeroes_ones_twos(Node* head) {
    Node* zeroesHead = new Node(-1);
    Node* onesHead = new Node(-1);
    Node* twosHead = new Node(-1);
    Node* zeroesTail = zeroesHead;
    Node* onesTail = onesHead;
    Node* twosTail = twosHead;

    Node* temp = head;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        current->next = NULL;

        if (current->data == 0) {
            zeroesTail->next = current;
            zeroesTail = current;
        } else if (current->data == 1) {
            onesTail->next = current;
            onesTail = current;
        } else {
            twosTail->next = current;
            twosTail = current;
        }
    }

    zeroesTail->next = onesHead->next;
    onesTail->next = twosHead->next;
    Node* sortedHead = zeroesHead->next;

    // Optional cleanup
    // delete zeroesHead;
    // delete onesHead;
    // delete twosHead;

    return sortedHead;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    Node* temp = sort_zeroes_ones_twos(head);

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
