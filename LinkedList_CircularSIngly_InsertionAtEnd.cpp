#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the end of a circular linked list
Node *insertEnd(Node *tail, int value)
{
    Node *newNode = new Node(value);
    if (tail == nullptr){
        // If the list is empty, initialize it with the new node
        tail = newNode;

        // Point to itself to form a circular structure
        newNode->next = newNode;
    }
    else{
        // Insert new node after the current tail
        // and update the tail pointer.
        // New node points to the head node
        newNode->next = tail->next;

        // Tail node points to the new node
        tail->next = newNode;

        // Update tail to be the new node
        tail = newNode;
    }
    return tail;
}

void printList(Node *last){
  if(last == NULL) return;
  
    // Start from the head node
    Node *head = last->next;
    while (true){
        cout << head->data << " ";
        head = head->next;
        if (head == last->next)
            break;
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

    // Insert elements at the end of the circular linked list
    last = insertEnd(last, 5);
    last = insertEnd(last, 6);

    cout << "List after inserting 5 and 6: ";
    printList(last);

    return 0;
}
