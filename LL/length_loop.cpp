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

int length(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int cnt = 1;
            fast = fast->next;
            while (slow != fast) {
                fast = fast->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // cycle at node 3

    int cycleLen = length(head);
    if (cycleLen > 0) {
        cout << "Cycle length is " << cycleLen << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
