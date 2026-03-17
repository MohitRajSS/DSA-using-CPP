#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int start, end, currSize, maxSize;

public:
    Queue() {
        maxSize = 16;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void Push(int data) {
        if (currSize == maxSize) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = data;
        currSize++;
        cout << "Element pushed: " << data << endl;
    }

    int pop() {
        if (end == -1) {
            cout << "The queue is empty" << endl;
            return -1;
        }
        int x = arr[start];
        if (start == end) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return x;
    }

    int top() {
        if (end == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }

    int size() {
        return currSize;
    }
};

int main() {
    Queue q(6);
    q.Push(4);
    q.Push(14);
    q.Push(24);
    q.Push(34);

    cout << "The peek of the queue before deleting any element: " << q.top() << endl;
    cout << "The size of the queue before deletion: " << q.size() << endl;
    cout << "The first element to be deleted: " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element: " << q.top() << endl;
    cout << "The size of the queue after deleting an element: " << q.size() << endl;

    return 0;
}
