#include <iostream>

using namespace std;

// Node structure for the Doubly Linked List
struct Node {
    int key;
    Node* prev;
    Node* next;

    Node(int k) : key(k), prev(nullptr), next(nullptr) {} // Constructor
};

// Class for the Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {} // Constructor

    // Function to add a node to the end of the list
    void addNode(int k) {
        Node* newNode = new Node(k);
        if (head == nullptr) {
            head = tail = newNode; // If list is empty
        } else {
            tail->next = newNode; // Link new node at the end
            newNode->prev = tail;
            tail = newNode; // Update tail
        }
        size++;
        cout << "Added node with key: " << k << endl; // Optional confirmation message
    }

    // Function to traverse and print the list
    void traverse() {
        Node* current = head; // Start from the head
        while (current != nullptr) {
            cout << current->key << " "; // Print key of the node
            current = current->next; // Move to the next node
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next; // Move head to next node
            delete temp; // Free memory
        }
    }
};

// Driver Code
int main() {
    DoublyLinkedList dll;

    // Adding nodes to the list
    dll.addNode(2);
    dll.addNode(4);
    dll.addNode(9);
    cout << "Linked List after adding nodes: ";
    dll.traverse();

    return 0;
}
