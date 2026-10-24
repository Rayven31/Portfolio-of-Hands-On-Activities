#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node *head = NULL, *tail = NULL;

// Push element onto the stack
void push(int newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head = newNode;
    }
}

// Pop element from the stack
int pop() {
    if (head == NULL) {
        cout << "Stack Underflow." << endl;
        return -1;
    }

    Node *temp = head;
    int tempVal = temp->data;

    head = head->next;

    // If stack becomes empty
    if (head == NULL) {
        tail = NULL;
    }

    delete temp;
    return tempVal;
}

// Display top element
void Top() {
    if (head == NULL) {
        cout << "Stack is Empty." << endl;
    } else {
        cout << head->data << endl;
    }
}

int main() {
    push(1);
    cout << "After the first PUSH, top of stack is: ";
    Top();

    push(5);
    cout << "After the second PUSH, top of stack is: ";
    Top();

    cout << "Popped: " << pop() << endl;
    cout << "After the first POP, top of stack is: ";
    Top();

    cout << "Popped: " << pop() << endl;
    cout << "After the second POP, top of stack is: ";
    Top();

    cout << "Popped: " << pop() << endl;

    return 0;
}
