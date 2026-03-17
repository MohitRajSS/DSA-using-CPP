#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};

Node* startingpt(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // cycle at node 3

    Node* start = startingpt(head);
    if (start) {
        cout << "Cycle starts at node with value: " << start->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
