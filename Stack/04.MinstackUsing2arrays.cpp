#include <iostream>
using namespace std;

struct Stack {
    int *arr;
    int *minarr;
    int size;
    int top;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        minarr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(top == size - 1) {
            cout << "Stack Overflow" << endl;
            return; 
        }

        arr[++top] = element;

        if(top == 0) {
            minarr[top] = element;
        } else {
            if(minarr[top - 1] < element)
                minarr[top] = minarr[top - 1];
            else
                minarr[top] = element;
        }
    }

    void display() {
        if(top == -1) {
            cout << "Stack is empty";
            return;
        }

        cout << "Original Stack: " << endl;
        for(int i = top; i >= 0; i--)
            cout << arr[i] << endl;

        cout << "Minstack: " << endl;
        for(int i = top; i >= 0; i--)
            cout << minarr[i] << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Stack s(n);

    for(int i = 0; i < n; i++) {
        int element;
        cin >> element;
        s.push(element);
    }

    s.display();
}
