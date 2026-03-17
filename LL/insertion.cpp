#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;           
    }
};

void printLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insert_node_head(Node* head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* insert_node_position(Node*head,int k,int data1){
    Node*temp=head;
    int cnt=0;
    while(cnt==k-1){
        temp=temp->next;
        cnt++;
    }
    Node*newNode=new Node(data1);
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}

Node* delete_node_tail(Node*head){
    if (head==nullptr||head->next==nullptr){
        return nullptr;
    }
    Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}

Node*delete_at_position(Node*head,int pos){
    int cnt=0;
    Node*temp=head;
    Node*prev=nullptr;

    if(head==nullptr){
        return nullptr;
    }
    while(temp!=nullptr){
        cnt++;
        if(cnt==pos){
            prev->next=prev->next->next;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    Node* head = new Node(arr[0]);
    printLL(head);
    head->next = new Node(arr[1]);
    printLL(head);
    head->next->next = new Node(arr[2]);
    printLL(head);
    head->next->next->next = new Node(arr[3]);
    printLL(head);
    cout << "Original Linked List: ";
    printLL(head);

    // Inserting at head
    head = insert_node_head(head, val);

    cout << "After Inserting at Head: ";
    printLL(head);

    return 0;
}
