#include <iostream>
#include <string>
using namespace std;

// Node class for the linked list stack
class Node {
public:
    char info; // Store character information
    Node* link; // Pointer to the next node

    Node(char value) {
        info = value; // Initialize info
        link = nullptr; // Initially, link is null
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr; // Initialize top to null
    }

    bool isempty() {
        return (top == nullptr); // Stack is empty if top is null
    }

    void push(char x) {
        Node* newNode = new Node(x); // Create a new node
        newNode->link = top; // Link new node to the previous top
        top = newNode; // Update top to the new node
    }

    char pop() {
        if (isempty()) {
            return '\0'; // Return null character if empty
        } else {
            char value = top->info; // Get the info from the top node
            Node* temp = top; // Store the current top
            top = top->link; // Update top to the next node
            delete temp; // Free memory
            return value; // Return popped value
        }
    }

    char peek() {
        if (isempty()) {
            return '\0'; // Return null character if empty
        } else {
            return top->info; // Return info from the top node
        }
    }

    ~Stack() {
        while (!isempty()) {
            pop(); // Call pop to delete all nodes
        }
    }
};

// Function to determine the precedence of operators
int prec(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '^') {
        return 3;
    }
    return 0;
}

// Function to convert infix expression to postfix
string convert(string infix) {
    string postfix = "";
    Stack s; // Create a stack object
    int i = 0;

    while (infix[i] != '\0') {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i]; // Append operand to postfix
            i++;
        } else if (infix[i] == '(') {
            s.push(infix[i]); // Push '(' onto the stack
            i++;
        } else if (infix[i] == ')') {
            while (s.peek() != '(' && !s.isempty()) {
                postfix += s.pop(); // Pop from stack until '(' is found
            }
            s.pop(); // Pop '(' from the stack
            i++;
        } else {
            while (!s.isempty() && (prec(s.peek()) >= prec(infix[i]))) {
                postfix += s.pop(); // Pop operators with higher or equal precedence
            }
            s.push(infix[i]); // Push current operator onto the stack
            i++;
        }
    }

    // Pop all remaining operators from the stack
    while (!s.isempty()) {
        postfix += s.pop();
    }

    cout << "Postfix is: " << postfix << endl; // Output the postfix expression
    return postfix;
}

// Main function
int main() {
    string infix = "a*b+c/d-e^f"; // Input infix expression
    string postfix = convert(infix); // Convert to postfix
    return 0;
}
