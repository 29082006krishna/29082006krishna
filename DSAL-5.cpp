#include <iostream>
using namespace std;

// Node class to represent each element in the queue
class Node {
public:
    int info;       
    Node* link;     

    Node(int value) : info(value), link(nullptr) {} 
};

// Queue class using linked list
class Queue {
private:
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {} // Initialize front and rear to nullptr

    void enqueue() {
        int x;
        cout << "Enter a number: ";
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
            cout << "UNDERFLOW: Queue is empty." << endl;
            return;
        }

        cout << "The deleted number is: " << front->info << endl; // Print the deleted value
        Node* temp = front; // Store the current front node
        front = front->link; // Move front to the next node

        if (front == nullptr) { // If the queue is now empty
            rear = nullptr; // Set rear to nullptr
        }

        delete temp; // Free memory of the old front node
    }

    void display() {
        if (front == nullptr) { // If the queue is empty
            cout << "THE QUEUE IS EMPTY." << endl;
            return;
        }

        cout << "CURRENT STATUS OF QUEUE: ";
        Node* current = front; // Start from the front node
        while (current != nullptr) {
            cout << "Value: " << current->info << " ";
            current = current->link; // Move to the next node
        }
        cout << endl;
    }

    void search() {
        int y;
        cout << "Enter a number to search: ";
        cin >> y;

        if (front == nullptr) { // If the queue is empty
            cout << "THE QUEUE IS EMPTY." << endl;
            return;
        }

        Node* current = front; // Start from the front node
        bool found = false; // Flag to track if the number is found
        int index = 0; // Index counter

        while (current != nullptr) {
            if (y == current->info) { // Check if the current node's info matches the search value
                cout << "Number found at index: " << index << endl;
                found = true;
            }
            current = current->link; // Move to the next node
            index++;
        }

        if (!found) {
            cout << "Number not found in the queue." << endl; // If not found
        }
    }
};

int main() {
    Queue q; // Create a queue object
    int ch;

    do {
        cout << endl << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Search" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
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
                q.search();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (ch != 5);

    return 0;
}
