#include <iostream>
using namespace std;

const int maxCap = 100;
int stack[maxCap];
int top = -1;
int maxSize;
int newData;

void push();
void pop();
void Top();
bool isEmpty();

int main() {
    int choice;

    cout << "Enter number of maximum elements for the stack (1-100): ";
    cin >> maxSize;

    if (maxSize < 1 || maxSize > maxCap) {
        cout << "Invalid stack size!" << endl;
        return 0;
    }

    do {
        cout << "\n===== STACK OPERATIONS =====" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. TOP" << endl;
        cout << "4. isEMPTY" << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                Top();
                break;

            case 4:
                if (isEmpty())
                    cout << "True - Stack is Empty." << endl;
                else
                    cout << "False - Stack is NOT Empty." << endl;
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid Choice." << endl;
        }

    } while (choice != 5);

    return 0;
}

bool isEmpty() {
    return (top == -1);
}

void push() {
    if (top == maxSize - 1) {
        cout << "Stack Overflow." << endl;
        return;
    }

    cout << "Enter new value: ";
    cin >> newData;

    stack[++top] = newData;

    cout << newData << " pushed into the stack." << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow." << endl;
        return;
    }

    cout << "Popped: " << stack[top] << endl;
    top--;
}

void Top() {
    if (isEmpty()) {
        cout << "Stack is Empty." << endl;
        return;
    }

    cout << "Top element: " << stack[top] << endl;
}