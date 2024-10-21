#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to delete a specific node in the circular linked list
Node* deleteSpecificNode(Node* last, int key) {
    if (last == nullptr) {
        // If the list is empty
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }

    Node* curr = last->next;
    Node* prev = last;

    // If the node to be deleted is the only node in the list
    if (curr == last && curr->data == key) {
        delete curr;
        last = nullptr;
        return last;
    }

    // If the node to be deleted is the first node
    if (curr->data == key) {
        last->next = curr->next;
        delete curr;
        return last;
    }

    // Traverse the list to find the node to be deleted
    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is found
    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        delete curr;
    } else {
        // If the node to be deleted is not found
        cout << "Node with data " << key
          << " not found." << endl;
    }

    return last;
}

// Function to print the circular linked list
void printList(Node* last) {
     if (last == NULL){
        cout << "List is Empty";
        return;
    }

    Node *head = last->next;
    while (true){
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}

int main() {
    // Create circular linked list: 2, 3, 4
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    // Delete a specific node
    int key = 3;
    last = deleteSpecificNode(last, key);

    cout << "List after deleting node " << key << ": ";
    printList(last);

    return 0;
}
