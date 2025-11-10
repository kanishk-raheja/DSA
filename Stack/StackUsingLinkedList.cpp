#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
struct Stack {
    Node* top;
    Stack() {
        top = nullptr;
    }
    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "\nStack elements (top → bottom):\n";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of elements to push: ";
    cin >> n;
    Stack s;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        s.push(element);
    }
    s.display();
    return 0;
}
