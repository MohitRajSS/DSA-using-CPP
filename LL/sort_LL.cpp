#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};

// --- Find node just before the middle ---
Node* findMiddlePrev(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return prev;
}

// --- Merge two sorted lists ---
Node* merge(Node* head1, Node* head2) {
    Node* resultHead = new Node(-1);
    Node* resultTail = resultHead;
    Node* t1 = head1;
    Node* t2 = head2;

    while (t1 != NULL && t2 != NULL) {
        if (t1->data <= t2->data) {
            resultTail->next = t1;
            t1 = t1->next;
        } else {
            resultTail->next = t2;
            t2 = t2->next;
        }
        resultTail = resultTail->next;
        resultTail->next = NULL;
    }

    if (t1) resultTail->next = t1;
    if (t2) resultTail->next = t2;

    Node* sorted = resultHead->next;
    delete resultHead;
    return sorted;
}

// --- Merge Sort on linked list ---
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* midPrev = findMiddlePrev(head);
    Node* right = midPrev->next;
    midPrev->next = NULL;

    Node* leftSorted = mergeSort(head);
    Node* rightSorted = mergeSort(right);

    return merge(leftSorted, rightSorted);
}

// --- Helpers ---
Node* createList(const vector<int>& v) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int x : v) {
        Node* n = new Node(x);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// --- Main ---
int main() {
    vector<int> data = {4, 2, 5, 3, 1};
    Node* list = createList(data);

    cout << "Before sort: ";
    printList(list);

    Node* sorted = mergeSort(list);

    cout << "After  sort: ";
    printList(sorted);

    return 0;
}
