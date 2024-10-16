#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a singly circular linked list with one node
Node* createCircularLinkedList(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = newNode;  // Points to itself to form the circular link
    return newNode;
}

// Function to display the circular linked list
void display(Node* last) {
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

int main() {
    // Create a circular linked list with one node
    Node* last = createCircularLinkedList(10);

    // Display the circular linked list
    cout << "Circular Linked List: ";
    display(last);

    return 0;
}
