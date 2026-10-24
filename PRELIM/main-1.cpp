#include <iostream>

// Constants & Global variables
constexpr int MAX_SIZE = 10;
int stackArr[MAX_SIZE];
int topIndex = -1; // Renamed to avoid clashing with function names

// Function prototypes
bool isEmpty();
bool isFull();
void top();
void push();
void pop();

int main() {
    int choice;
    bool running = true;

    // Menu loop so the user can perform multiple operations
    while (running) {
        std::cout << "\n===========================\n";
        std::cout << " Stack Operations: \n";
        std::cout << " [1] Push\n [2] Pop\n [3] Is Empty?\n [4] Is Full?\n [5] View Top\n [6] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) {
                    std::cout << "The stack IS empty.\n";
                } else {
                    std::cout << "The stack is NOT empty.\n";
                }
                break;
            case 4:
                if (isFull()) {
                    std::cout << "The stack IS full.\n";
                } else {
                    std::cout << "The stack is NOT full.\n";
                }
                break;
            case 5:
                top();
                break;
            case 6:
                running = false;
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}

// Function definitions:

bool isEmpty() {
    return (topIndex == -1);
}

bool isFull() {
    return (topIndex == MAX_SIZE - 1);
}

void top() {
    // Error catching: check if empty before accessing top element
    if (isEmpty()) {
        std::cout << "Stack Underflow! The stack is empty.\n";
        return;
    }

    // Prints the top element
    std::cout << "The top element is: " << stackArr[topIndex] << std::endl;
}

void push() {
    // Error catching: check if full before adding elements
    if (isFull()) {
        std::cout << "Stack Overflow! Cannot push more elements.\n";
        return;
    }

    int newData;
    // Ask the user for input
    std::cout << "Enter an integer to push: ";
    std::cin >> newData;

    // Increment top first, then assign the new data
    topIndex++;
    stackArr[topIndex] = newData;
    std::cout << "Successfully pushed " << newData << " to the stack.\n";
}

void pop() {
    // Error catching: check if empty before popping elements
    if (isEmpty()) {
        std::cout << "Stack Underflow! Cannot pop from an empty stack.\n";
        return;
    }

    // Display the item to be popped and decrement top
    std::cout << "Popping: " << stackArr[topIndex] << std::endl;
    topIndex--;
}