#include <iostream>
using namespace std;

struct Stack
{
    int *arr;
    int size;
    int top;

    // Constructor
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push operation
    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        arr[++top] = element;
    }

    // Display operation
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "\nStack elements (top → bottom):" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    // Destructor to free memory
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    Stack s(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        s.push(element);
    }

    s.display();

    return 0;
}
