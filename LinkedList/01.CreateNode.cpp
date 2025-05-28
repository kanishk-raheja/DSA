#include <iostream>
using namespace std;

struct Node {
    int data;      // Data part
    Node* next;    // Pointer to the next node

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main() {
    Node* head = new Node(10);
    cout << "Data in the node: " << head->data << endl;
    return 0;
}
