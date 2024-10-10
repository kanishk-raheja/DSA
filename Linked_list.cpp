#include <iostream>
using namespace std;

struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize the node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked List class
class LinkedList {
    Node* head;  // Pointer to the first node of the list

public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to display the contents of the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    LinkedList list;

    // Insert nodes into the list
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Display the list
    cout << "Linked List: ";
    list.display();

    return 0;
}
