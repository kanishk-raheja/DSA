#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the beginning of the
// circular linked list
Node* insertAtBeginning(Node* last, int value){
    // Allocate memory for the new node and set its data
    Node* newNode = new Node(value);

    // If the list is empty, make the new node point to
    // itself and set it as last
    if (last == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    // Insert the new node at the beginning
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

void printList(Node* last){
  if(last == NULL) return;
  
    // Start from the head node
    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next)
            break;
    }
    cout << endl;
}

int main(){

    // Create circular linked list: 2, 3, 4
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    // Insert 5 at the beginning
    last = insertAtBeginning(last, 5);

    cout << "List after inserting 5 at the beginning: ";
    printList(last);

    return 0;
}
