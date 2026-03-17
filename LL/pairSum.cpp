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

int pairs_sum(Node* head, int target) {
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    Node* first = head;
    int count = 0;

    while (first != NULL && last != NULL && first != last && first->prev != last) {
        int sum = first->data + last->data;

        if (sum > target) {
            last = last->prev;
        } else if (sum < target) {
            first = first->next;
        } else {
            count++;
            first = first->next;
            last = last->prev;
        }
    }
    return count;
}


int main(){
Node* head = new Node(1);
head->next = new Node(3);
head->next->prev = head;

head->next->next = new Node(4);
head->next->next->prev = head->next;

head->next->next->next = new Node(5);
head->next->next->next->prev = head->next->next;

head->next->next->next->next = new Node(6);
head->next->next->next->next->prev = head->next->next->next;

head->next->next->next->next->next = new Node(8);
head->next->next->next->next->next->prev = head->next->next->next->next;

head->next->next->next->next->next->next = new Node(9);
head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

cout << "Number of pairs: " << pairs_sum(head, 10) << endl;

    return 0;

}







