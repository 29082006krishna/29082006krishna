#include <iostream>
using namespace std;

// Node class to represent each element in the queue
class Node {
public:
    int info;  // The value of the node
    Node* link; // Pointer to the next node

    Node(int value) : info(value), link(nullptr) {} // Constructor
};

// Queue class using linked list
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {} // Initialize front and rear to nullptr

    void enqueue() {
        int x;
        cout << "Enter value of x: ";
        cin >> x;
        Node* newNode = new Node(x); // Create a new node

        if (rear == nullptr) { // If the queue is empty
            front = rear = newNode; // Both front and rear point to the new node
            cout << x << " inserted into queue." << endl;
            return;
        }

        rear->link = newNode; // Link the new node to the end of the queue
        rear = newNode;       // Update rear to the new node
        cout << x << " inserted into queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) { // If the queue is empty
            cout << "QUEUE IS UNDERFLOW" << endl;
            return;
        }

        cout << "Deleted element is: " << front->info << endl; // Print the deleted value
        Node* temp = front; // Store the current front node
        front = front->link; // Move front to the next node

        if (front == nullptr) { // If the queue is now empty
            rear = nullptr; // Set rear to nullptr
        }

        delete temp; // Free memory of the old front node
    }

    void display() {
        if (front == nullptr) { // If the queue is empty
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }

        cout << "CURRENT STATUS OF QUEUE: ";
        Node* current = front; // Start from the front node
        while (current != nullptr) {
            cout << current->info << " "; // Print each node's info
            current = current->link; // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    Queue q; // Create a queue object
    int ch;

    do {
        cout << "Press [1] to insert" << endl;
        cout << "Press [2] to delete" << endl;
        cout << "Press [3] to display" << endl;
        cout << "Press [4] to exit" << endl;
        cout << "Enter ch: ";
        cin >> ch;

        switch (ch) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
        }
    } while (ch != 4);

    return 0;
}
