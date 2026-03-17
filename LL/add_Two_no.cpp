#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data1, Node *next1 = NULL)
    {
        data = data1;
        next = next1;
    }
};

Node *reverse(Node *head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    Node *newHead = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node* Add(Node* head1, Node* head2)
{
    Node* temp1 = reverse(head1);
    Node* temp2 = reverse(head2);
    int carry = 0;
    Node* resultHead = new Node(-1);
    Node* resultTail = resultHead;

    while (temp1 != NULL || temp2 != NULL || carry)
    {
        int val1 = (temp1 != NULL) ? temp1->data : 0;
        int val2 = (temp2 != NULL) ? temp2->data : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;

        Node* newNode = new Node(sum % 10);
        resultTail->next = newNode;
        resultTail = newNode;

        if (temp1) temp1 = temp1->next;
        if (temp2) temp2 = temp2->next;
    }

    Node* result = reverse(resultHead->next);
    delete resultHead;
    return result;
}
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
Node* createList(const vector<int>& digits) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int d : digits) {
        Node* newNode = new Node(d);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    Node* num1 = createList({9, 9, 9}); // 617
    Node* num2 = createList({9, 9, 9}); // 295

    Node* sum = Add(num1, num2);

    cout << "Sum: ";
    printList(sum); // Expected: 9 -> 1 -> 2

    return 0;
}
