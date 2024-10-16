#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a doubly circular linked list with one node
Node* createDoublyCircularLinkedList(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = newNode;  // Points to itself to form the circular link
    newNode->prev = newNode;  // Points to itself in the reverse direction as well
    return newNode;
}

// Function to display the circular linked list in forward direction
void displayForward(Node* last) {
    if (last == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = last->next;  // Start from the first node
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);  // Loop until we come back to the first node

    cout << endl;
}

// Function to display the circular linked list in reverse direction
void displayBackward(Node* last) {
    if (last == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = last;  // Start from the last node
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != last);  // Loop until we come back to the last node

    cout << endl;
}

int main() {
    // Create a doubly circular linked list with one node
    Node* last = createDoublyCircularLinkedList(10);

    // Display the circular linked list in forward and reverse directions
    cout << "Doubly Circular Linked List (Forward): ";
    displayForward(last);

    cout << "Doubly Circular Linked List (Backward): ";
    displayBackward(last);

    return 0;
}
