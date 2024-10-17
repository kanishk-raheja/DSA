#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at a specific position in a circular linked list
Node *insertAtPosition(Node *last, int data, int pos){
    if (last == nullptr){
        // If the list is empty
        if (pos != 1){
            cout << "Invalid position!" << endl;
            return last;
        }
        // Create a new node and make it point to itself
        Node *newNode = new Node(data);
        last = newNode;
        last->next = last;
        return last;
    }

    // Create a new node with the given data
    Node *newNode = new Node(data);

    // curr will point to head initially
    Node *curr = last->next;

    if (pos == 1){
        // Insert at the beginning
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    // Traverse the list to find the insertion point
    for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;
      
        // If position is out of bounds
        if (curr == last->next){
            cout << "Invalid position!" << endl;
            return last;
        }
    }
    // Insert the new node at the desired position
    newNode->next = curr->next;
    curr->next = newNode;

    // Update last if the new node is inserted at the end
    if (curr == last) last = newNode;

    return last;
}

void printList(Node *last){
    if (last == NULL) return;

    Node *head = last->next;
    while (true){
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}

int main(){
    // Create circular linked list: 2, 3, 4
    Node *first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node *last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    // Insert elements at specific positions
    int data = 5, pos = 2;
    last = insertAtPosition(last, data, pos);
    cout << "List after insertions: ";
    printList(last);

    return 0;
}
