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

// Function to delete the first node of the circular linked list
Node* deleteFirstNode(Node* last) {
    if (last == nullptr) {
        // If the list is empty
        cout << "List is empty" << endl;
        return nullptr;
    }

    Node* head = last->next;

    if (head == last) {
        // If there is only one node in the list
        delete head;
        last = nullptr;
    } else {
        // More than one node in the list
        last->next = head->next;
        delete head;
    }

    return last;
}

void printList(Node* last) {
    if(last == NULL) return ;
 
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

    // Delete the first node
    last = deleteFirstNode(last);

    cout << "List after deleting first node: ";
    printList(last);

    return 0;
}
