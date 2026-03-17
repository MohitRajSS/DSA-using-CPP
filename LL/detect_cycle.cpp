#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};

bool detect(Node* head) {
    Node* temp = head;
    unordered_map<Node*, int> nodemap;
    while (temp != NULL) {
        if (nodemap.find(temp) != nodemap.end()) {
            return true;
        }
        nodemap[temp] = 1;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(3)));

    bool hasCycle = detect(head);

    if (hasCycle) {
        cout << "Cycle detected in linked list." << endl;
    } else {
        cout << "No cycle detected in linked list." << endl;

        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
