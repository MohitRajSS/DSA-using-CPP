#include<iostream>
using namespace std;

class Stack {
public:
    int top;
    int size;
    int* arr;

    Stack() {
        top = -1;
        size = 10;
        arr = new int[size];
    }

    void push(int x) {
        top++;
        arr[top] = x;
    }

    int pop() {
        int x = arr[top];
        top--;
        return x;
    }

    int getTop() {
        return arr[top];
    }

    int getSize() {
        return top + 1;
    }
};

int main() {
    Stack st;
    int choice;

    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Size\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (st.top == st.size - 1) {
                    cout << "Stack is full.\n";
                    break;
                }
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                cout << value << " pushed.\n";
                break;
            }

            case 2: {
                if (st.top == -1) {
                    cout << "Stack is empty.\n";
                } else {
                    int x = st.pop();
                    cout << "Popped: " << x << endl;
                }
                break;
            }

            case 3: {
                if (st.top == -1) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Top element: " << st.getTop() << endl;
                }
                break;
            }

            case 4: {
                cout << "The size of the stack is: " << st.getSize() << endl;
                break;
            }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
