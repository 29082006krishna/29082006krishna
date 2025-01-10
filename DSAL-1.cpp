#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int info;     // Information field (previously infop)
    Node* link;   // Pointer to the next node (previously next)

    // Constructor to initialize the node
    Node(int value) {
        info = value;   // Initialize info
        link = nullptr; // Initially, link is null
    }
};

// Stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor initializes top to nullptr
    Stack() {
        top = nullptr;
    }

    // Push method to add an element to the stack
    void push() {
        int x;
        cout << "Enter element: ";
        cin >> x;
        Node* newNode = new Node(x); // Create a new node with input data
        newNode->link = top;          // Link new node to previous top
        top = newNode;                // Update top to new node
    }

    // Pop method to remove an element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Underflow" << endl;
            cout << "Exit" << endl;
            return;
        } else {
            cout << "Deleted element is: " << top->info << endl;
            Node* temp = top;     // Store the current top
            top = top->link;      // Update top to next node
            delete temp;          // Free memory
        }
    }

    // Peep method to view an element at a specific index from the top
    void peep() {
        int index;
        cout << "Enter user index: ";
        cin >> index;

        Node* current = top;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                cout << "INVALID" << endl;
                cout << "Exit" << endl;
                return;
            }
            current = current->link; // Move to the next node
        }
        if (current != nullptr) {
            cout << "Element at index " << index << " is: " << current->info << endl;
        } else {
            cout << "INVALID" << endl;
            cout << "Exit" << endl;
        }
    }

    // Change method to modify an element at a specific index from the top
    void change() {
        int index, value;
        cout << "Enter index: ";
        cin >> index;
        cout << "Enter new value: ";
        cin >> value;

        Node* current = top;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                cout << "INVALID" << endl;
                cout << "Exit" << endl;
                return;
            }
            current = current->link; // Move to the next node
        }
        if (current != nullptr) {
            current->info = value; // Change the value
            cout << "Element at index " << index << " changed to: " << current->info << endl;
        } else {
            cout << "INVALID" << endl;
            cout << "Exit" << endl;
        }
    }

    // Display method to show all elements in the stack
    void display() {
        if (top == nullptr) {
            cout << "Underflow" << endl;
            cout << "Exit" << endl;
        } else {
            Node* current = top;
            cout << "Stack elements: ";
            while (current != nullptr) {
                cout << current->info << " "; // Print info
                current = current->link; // Move to the next node
            }
            cout << endl;
        }
    }

    // Exit method to indicate completion
    void exit() {
        cout << "The stack process is completed" << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            pop(); // Call pop to delete all nodes
        }
    }
};

int main() {
    Stack s; // Create a stack object
    int c;
    do {
        cout << "Press [1] to push the data in the stack" << endl;
        cout << "Press [2] to pop the data from the stack" << endl;
        cout << "Press [3] to peep the data" << endl;
        cout << "Press [4] to change the data of the stack" << endl;
        cout << "Press [5] to display the data" << endl;
        cout << "Press [6] to exit" << endl;
        cout << "Enter choice: ";
        cin >> c;
        switch (c) {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peep();
                break;
            case 4:
                s.change();
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.exit();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (c != 6);

    return 0;
}
