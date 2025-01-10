#include <iostream>
using namespace std;

// Node class to represent a disk
class Node {
public:
    int disk; // The disk number
    Node* next; // Pointer to the next disk

    Node(int d) : disk(d), next(nullptr) {} // Constructor
};

// Rod class to represent a rod with linked list
class Rod {
public:
    Node* top; // Pointer to the top disk

    Rod() : top(nullptr) {} // Initialize the top to nullptr

    // Push a disk onto the rod
    void push(int disk) {
        Node* newNode = new Node(disk);
        newNode->next = top; // Point to the current top disk
        top = newNode; // Update the top to the new disk
    }

    // Pop a disk from the rod
    int pop() {
        if (top == nullptr) {
            return -1; // Return -1 if the rod is empty
        } else {
            int disk = top->disk; // Get the top disk
            Node* temp = top; // Store the top node temporarily
            top = top->next; // Update top to the next disk
            delete temp; // Delete the old top node
            return disk; // Return the disk number
        }
    }

    // Peek at the top disk without removing it
    int peek() {
        return (top != nullptr) ? top->disk : -1; // Return -1 if the rod is empty
    }

    // Function to display the disks in the rod
    void display() {
        Node* current = top;
        cout << "Rod: ";
        while (current != nullptr) {
            cout << current->disk << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Function to perform the Tower of Hanoi algorithm
void TOH(int n, Rod& source, Rod& auxiliary, Rod& destination) {
    if (n == 1) {
        int disk = source.pop(); // Remove the top disk from the source rod
        destination.push(disk); // Place it on the destination rod
        cout << " Move disk " << disk << " from source to destination" << endl;
        return;
    }
    TOH(n - 1, source, destination, auxiliary); // Move n-1 disks to auxiliary
    int disk = source.pop(); // Move the nth disk from source to destination
    destination.push(disk);
    cout << " Move disk " << disk << " from source to destination" << endl;
    TOH(n - 1, auxiliary, source, destination); // Move the n-1 disks from auxiliary to destination
}

// Main function
int main() {
    int n;
    cout << " Enter the number of disks: ";
    cin >> n;

    Rod source, auxiliary, destination; // Create three rods

    // Initialize the source rod with disks
    for (int i = n; i >= 1; i--) {
        source.push(i); // Push disks onto the source rod
    }

    cout << "Initial state:" << endl;
    source.display(); // Display the initial state of the source rod

    TOH(n, source, auxiliary, destination); // Perform Tower of Hanoi

    cout << "Final state:" << endl;
    destination.display(); // Display the final state of the destination rod

    return 0;
}
